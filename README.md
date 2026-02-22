# Chapter 05: Concurrent IO Models

- Performance limitations of older concurrent approaches, like creating a dedicated thread or process per client connection (high memory consumption).

- The Event-Driven Programming paradigm: allowing a single thread to serve thousands of clients using Non-Blocking IO.

- How readiness APIs work (`poll`, `epoll`, and `kqueue`), whose role is to notify the system which sockets have buffers with available data.

- Altering file descriptors (sockets) to non-blocking mode using the native `fcntl` syscall (O_NONBLOCK).