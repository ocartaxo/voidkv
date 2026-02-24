#include "buffer.h"
#include <cstring>
#include <algorithm>

void buf_consume(Buffer *buf, size_t n) {
  buf->data_begin += n;
  if (buf->data_begin > buf->data_end) {
    buf->data_begin = buf->data_end;
  }
}

void buf_append(Buffer *buf, const uint8_t *data, size_t len) {
  size_t cur_data_size = buf_size(buf);
  size_t capacity = buf_capacity(buf);
  size_t available_space = buf_available_space(buf);

  // 1st strategy (compaction strategy): move the data to the front if it helps
  if(available_space < len) {
    std::memmove(buf->buffer_begin, buf->data_begin, cur_data_size);
    buf->data_begin = buf->buffer_begin;
    buf->data_end = buf->data_begin + cur_data_size;

    // recaculate the available space at the end after compaction
    available_space = buf->buffer_end - buf->data_end;
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
      std::memcpy(new_buffer, buf->data_begin, cur_data_size);
    }

    // free the old buffer's memory to prevent memory
    delete[] buf->buffer_begin;

    // update all pointers
    buf->buffer_begin = new_buffer;
    buf->buffer_end = new_buffer + new_capacity;
    buf->data_begin = new_buffer;
    buf->data_end = new_buffer + cur_data_size;
  }

  // finally, with guaranteed space, we append the new data at the end
  std::memmove(buf->data_end, data, len);
  buf->data_end += len;

}
