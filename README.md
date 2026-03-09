# VoidKV: Key-Value Store on Network

## About the project
This project is a high-performance Key-Value Store implementation, developed in C/C++.

### 🚀 Overview
**VoidKV** is an educational project designed to explore the fundamentals of distributed systems and in-memory databases. The primary goal is to build a fully functional Redis clone from the ground up, focusing on two core pillars:

1. **Network Programming**: Implementing TCP sockets, request-response protocols, and concurrent I/O models (Event Loops).

2. **Data Structures**: Implementing progressive hash tables, balanced binary trees (AVL) for Sorted Sets, and heaps for TTL (Time-to-Live) management.

Rather than relying on off-the-shelf libraries, this project takes a deep dive into low-level C and performance optimization.

## Getting Started

### Dependencies
To build and run this project, you will need:

- A Linux environment (Native, VM, or WSL).

- `g++` compiler (C++11 support or higher).

- `make` for build automation.

### Installation
1. Clone the repository:
> git clone [https://github.com/ocartaxo/voidkv.git](https://github.com/ocartaxo/voidkv.git)
cd voidkv

2. Build the project using the Makefile
> make

### Usage
Once the build is complete, you will see two main binaries: `server` and `client`.

1. Start the server
> ./server

2. In a separate terminal, run the client to send commands
> ./client

### 🗺️ Roadmap

The following milestones track the project's progress, organized by book chapters. Each link points to the branch where the specific feature was implemented:

- [x] [Chapter 3](https://github.com/ocartaxo/voidkv/tree/ch03)
- [x] [Chapter 4](https://github.com/ocartaxo/voidkv/tree/ch04)
- [x] [Chapter 5](https://github.com/ocartaxo/voidkv/tree/ch04)
- [x] [Chapter 6](https://github.com/ocartaxo/voidkv/tree/ch06)
- [x] [Chapter 7](https://github.com/ocartaxo/voidkv/tree/ch07)
- [x] [Chapter 8](https://github.com/ocartaxo/voidkv/tree/ch08)
- [ ] [Chapter 9](https://github.com/ocartaxo/voidkv/tree/ch09)
- [ ] [Chapter 10](https://github.com/ocartaxo/voidkv/tree/ch10)
- [ ] [Chapter 11](https://github.com/ocartaxo/voidkv/tree/ch11)
- [ ] [Chapter 12](https://github.com/ocartaxo/voidkv/tree/ch12)
- [ ] [Chapter 13](https://github.com/ocartaxo/voidkv/tree/ch13)
- [ ] [Chapter 14](https://github.com/ocartaxo/voidkv/tree/ch14)

> Note: Chapters 1 and 2 are omitted as they cover introductory concepts and theoretical background without specific code implementations.

## Acknowledgments

This project was built following the concepts detailed in the book [Build Your Own Redis](https://build-your-own.org/redis/). You can find more hands-on engeneering projects like this over at [build-your-own.org](https://build-your-own.org).

## License
This project is licensed under the MIT License - see the [license](LICENSE) file for details.
