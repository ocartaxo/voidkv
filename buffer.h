#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <string_view>
#include <string>

// error code for TAG_ERR
enum {
    ERR_UNKNOWN = 1, // unknown command
    ERR_TOO_BIG = 2, // response too big
};

// data types of serialized data
enum {
  TAG_NIL = 0, // nil
  TAG_ERR = 1, // error code + msg
  TAG_STR = 2, // string
  TAG_INT = 3, // int64
  TAG_DBL = 4, // double
  TAG_ARR = 5, // array
};

struct Buffer {
  uint8_t *buffer_begin = nullptr;
  uint8_t *buffer_end = nullptr;
  uint8_t *data_begin = nullptr;
  uint8_t *data_end = nullptr;

  // RAII constructor
  Buffer(size_t initial_capacity = 0) {
    if(initial_capacity > 0) {
      buffer_begin = new uint8_t[initial_capacity];
      buffer_end = buffer_begin + initial_capacity;
      data_begin = buffer_begin;
      data_end = buffer_end;
    }
  }

  // free the memory (RAII destructor)
  ~Buffer() {
    delete[] buffer_begin;
  }

  // copy prevention (C++11)
  Buffer(const Buffer&) = delete;
  Buffer& operator=(const Buffer&) = delete;
};

void buf_consume(Buffer &buf, size_t n);

void buf_append(Buffer &buf, const uint8_t *data, size_t len);

void buf_resize(Buffer &buf, size_t new_capacity);

void out_nil(Buffer &out);

void out_str(Buffer &out, const char *s, size_t size);

void out_int(Buffer &out, int64_t val);

void buf_append_u32(Buffer &buf, uint32_t data);

void out_err(Buffer &out, uint32_t code, const std::string &msg);

void out_arr(Buffer &out, uint32_t n);

inline size_t buf_size(const Buffer &buf) { return buf.data_end - buf.data_begin; }

inline size_t buf_capacity(const Buffer &buf) { return buf.buffer_end - buf.buffer_begin; }

inline size_t buf_available_space(const Buffer &buf) { return buf.buffer_end - buf.data_end; }