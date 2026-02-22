# Chapter 04: Request-Response Protocol

- The design of protocols based on Length prefixes compared to problematic delimiter-based protocols (like textual HTTP).

- The semantics of read and write syscalls: `read`/`write` can process fewer bytes than requested without an error (due to push/pull IO).

- Safe approach when checking the `errno` return in C, remembering it should only be analyzed after an explicit failure.

- Implementation of robust custom functions `read_full` and `write_all`, using loops to guarantee full transmissions in the continuous stream.

- Implementation of a binary protocol where messages consist of a 4-byte header indicating the payload size, followed by the request (e.g., a simple string).