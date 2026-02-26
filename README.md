# Chapter 08: Hashtables (Parts 1 & 2)

- Contrasting the complexity of Chaining tables vs Open addressing.

- The dreaded Worst-Case Latency problem $O(N)$ caused by the invisible resizing operation in standard C/C++/Go libraries.

- The robustness superiority of the "Intrusive Data Structures" technique (used by the Linux Kernel) over common Generics/Templates patterns.

- Understanding the Progressive Rehashing algorithm that undoes blocking latency by reallocating only a restricted subset of elements at a time.

- The math of "Powers of 2" used in masked allocations with bitwise AND (n & (size-1)), replacing expensive CPU modulo operations.

- Approach of injecting base structs into data, eliminating the double memory jump and simplifying the use of Garbage Collection in C/C++.

- Definition of the famous and crucial C Macro `container_of` and tricks with `offsetof` to retrieve root pointers from encapsulated child members.

- Implementation of the intrusive `HNode` structure holding pointers and its own hashes (`hcode`).

- Application of "Double Pointer Tricks" in C Linked List searches and removals (`**from`), abolishing the creation of special logic for list head manipulation.

- Definition of the master `HMap` struct, managing a new table and an old table during the transitional period (re-hash).

- Injection of the `hm_help_rehashing` method into daily database operations (`insert`, `delete`, `lookup`), ensuring incremental progress of memory restructuring.