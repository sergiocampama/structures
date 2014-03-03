structures
==========

This is a collection of basic structures for academic purposes. These are the implemented ones right now:

1. Linked List
2. Hash
3. Trie Tree
4. Binary Search Tree

Linked List
-----------

The list is doubly linked, and supports adding, removing and finding by key.

Hash
----

The hash structure solves collisions by chaining, with the hash table being pointers to linked lists. This linked list starts with a sentinel for easier support of removing nodes.

It supports adding and removing void pointer values (everything) using string keys, copying the value into new memory. 

Trie Tree
---------

The trie tree structure works very much like a hash, but the storage mechanism is more closely related to a tree. It supports void pointer values as well.

Binary Search Tree
---------

The binary search tree supports adding and deleting nodes, and finding by key, successors, predecessors, maximums and minimums.

Usage
=====

To test just `make`.
