#include "buffer.h"
#include <cstring>
#include <algorithm>

void buf_consume(Buffer &buf, size_t n) {
  buf.data_begin += n;
  if (buf.data_begin > buf.data_end) {
    buf.data_begin = buf.data_end;
  }
}

void buf_append(Buffer &buf, const uint8_t *data, size_t len) {
  size_t cur_data_size = buf_size(buf);
  size_t capacity = buf_capacity(buf);
  size_t available_space = buf_available_space(buf);

  // 1st strategy (compaction strategy): move the data to the front if it helps
  if(available_space < len) {
    std::memmove(buf.buffer_begin, buf.data_begin, cur_data_size);
    buf.data_begin = buf.buffer_begin;
    buf.data_end = buf.data_begin + cur_data_size;

    // recaculate the available space at the end after compaction
    available_space = buf.buffer_end - buf.data_end;
  }

  // 2nd strategy (reallocation strategy): if it STILL doesn't fit, it will need a larger array
  if (available_space < len) {
    // decide the new size: double the current capacity OR the exact required size (whichever is larger)
    size_t new_capacity = std::max(capacity * 2, cur_data_size + len);

    // if the original capacity was zero (uninitialized buffer), set a minimum initial size
    if (new_capacity == 0) new_capacity = 64;

    // alocate the new array
    uint8_t *new_buffer = new uint8_t[new_capacity];

    // copy existing data to the new space
    if (cur_data_size > 0) {
      std::memcpy(new_buffer, buf.data_begin, cur_data_size);
    }

    // free the old buffer's memory to prevent memory
    delete[] buf.buffer_begin;

    // update all pointers
    buf.buffer_begin = new_buffer;
    buf.buffer_end = new_buffer + new_capacity;
    buf.data_begin = new_buffer;
    buf.data_end = new_buffer + cur_data_size;
  }

  // finally, with guaranteed space, we append the new data at the end
  std::memmove(buf.data_end, data, len);
  buf.data_end += len;

}

void buf_resize(Buffer &buf, size_t new_capacity) {
  
  if (new_capacity <= buf_capacity(buf)) {
    return;
  }

  uint8_t *new_data = new uint8_t[new_capacity];

  size_t current_size = buf_size(buf);

  if (current_size > 0) {
    std::memcpy(new_data, buf.data_begin, current_size);
  }

  delete[] buf.buffer_begin;

  buf.buffer_begin = new_data;
  buf.buffer_end = buf.buffer_begin + new_capacity;
  buf.data_begin = buf.buffer_begin;
  buf.data_end = buf.data_begin + current_size;

}

// handle endian-ness
void buf_append_u8(Buffer &buf, uint8_t data) {
  buf_append(buf, &data, 1);
}

void buf_append_u32(Buffer &buf, uint32_t data) {
  buf_append(buf, (const uint8_t *)&data, 4);
}

void buf_append_i64(Buffer &buf, int64_t data) {
  buf_append(buf, (const uint8_t *)&data, 8);
}

void out_nil(Buffer &out) {
  buf_append_u8(out, TAG_NIL);
}

void out_str(Buffer &out, const char *s, size_t size) {
  buf_append_u8(out, TAG_STR);
  buf_append_u32(out, (uint32_t)size);
  buf_append(out, (const uint8_t *)s, size);
}

void out_int(Buffer &out, int64_t val) {
  buf_append_u8(out, TAG_INT);
  buf_append_i64(out, val);
}

void out_err(Buffer &out, uint32_t code, const std::string &msg) {
    buf_append_u8(out, TAG_ERR);
    buf_append_u32(out, code);
    buf_append_u32(out, (uint32_t)msg.size());
    buf_append(out, (const uint8_t *)msg.data(), msg.size());
}

void out_arr(Buffer &out, uint32_t n) {
  buf_append_u8(out, TAG_ARR);
  buf_append_u32(out, n);
}