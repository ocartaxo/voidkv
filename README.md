# Chapter 10: Balanced Binary Tree

- The Divide and conquer mechanics employed by binary trees as pillars for fast indexing for range queries.

- Guarantees and Invariants of the AVL Tree - why limiting subtrees to a maximum height difference of "1" preserves the unbreakable promise of $O(\log N)$ search.

- Theoretical understanding of Right/Left Rotations: the remapping of parent-child relations and preservation of middle elements.

- Robust definition of `AVLNode`, storing auxiliary `height` state without accumulating unnecessary `sizeof` space since it doesn't carry database Data payload.

- Flexible generic algorithm for top-down updating (Height updates) of branches, and evaluation for imbalance and climbing (fix left / fix right).

- Resolution of severe complexities in tree removals (Hard Case with two children), locating the leftmost successors of the right subtrees for contiguous swaps.