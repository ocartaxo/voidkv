# Chapter 03: TCP Server and Client

- Understanding Endianness: the discrepancy between the processor's byte order (Little-Endian) and the network standard (Big-Endian).

- The vital need for the `SO_REUSEADDR` socket option to allow immediate restart of TCP Servers.

- Steb-by-step implementation using the Linux Socket API (`socket`, `setsockopt`, `bind`, `listen`)

- Structuring and minipulating IPv4 addresses through the use of the `struct sockaddr_in` strucutre and `htons`/`htonl` conversions.

- Implementanting an infinite server loop that extracts completed connections via the a `accept` syscall.

-  Creating a client program that invokes `connect`, and uses generic Linux `read` and `write` calls to exchange simple strings.