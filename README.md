# Chapter 06: Event Loop (Parts 1 & 2)

- The mental transition from traditional procedural programming to state- and callback-based programming.

- The intrinsic need to maintain temporary buffers per connection for input data (incomplete requests) and output data (queued responses).

- The Pipelining technique, where clients send several consecutive requests at once to reduce network latency (Round Trip Time).

- Pitfalls when reading TCP byte streams: never assume that the data read in a single buffer iteration represents "only one request".

- Impact on processing the front buffer array: why normal vectors cause an $O(N^2)$ penalty when consuming commands in the middle of iterations.

- Creation of the central Conn class/struct that memorizes the read/write state and buffers of that network connection.

- Core implementation of the event matrix by dynamically manipulating a vector of struct pollfd instances passed to poll().

- Native handling of the EINTR case and safe reading of newly accepted clients through the read notification flag (POLLIN).

- Creation of the state transition machine (want_read vs want_write), which decides in which direction the socket should be checked in the next iteration.

- Critical read refactoring, swapping "if there's a request, process it" blocks for while(try_one_request(conn)) loops, ensuring the pipeline is drained.

- Introduction and validation of the optimistic non-blocking write concept (trying to use write directly before returning to the event loop, saving a poll syscall).