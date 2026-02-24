#pragma once

#include <stdint.h>
#include <stdlib.h>

#define BUFFER_CAPACITY 64*1024 // capacity of 64KB

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

void buf_consume(Buffer *buf, size_t n);

void buf_append(Buffer *buf, const uint8_t *data, size_t len);

inline size_t buf_size(const Buffer* buf) { return buf->data_end - buf->data_begin; }

inline size_t buf_capacity(const Buffer* buf) { return buf->buffer_end - buf->buffer_begin; }

inline size_t buf_available_space(const Buffer* buf) { return buf->buffer_end - buf->data_end; }
