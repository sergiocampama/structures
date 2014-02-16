structures
==========

This is a collection of basic structures for academic purposes. For now, it features a doubly linked list and a hash with chaining and universal hashing function.

Linked List
-----------

The list is doubly linked, and supports adding, removing and finding by key.

Hash
----

The hash structure solves collisions by chaining, with the hash table being pointers to linked lists. This linked list starts with a sentinel for easier support of removing nodes.

It supports adding and removing void pointer values (everything) using string keys, copying the value into new memory. 

Usage
=====

To compile just `make` and then run `bin/structures`
