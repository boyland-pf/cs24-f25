# Huffman Coding Assignment

## Overview

This assignment implements **Huffman coding**, a classic algorithm used for lossless data compression. You will use a **min-heap** (implemented with a `std::vector`) to store character frequencies and build a special binary tree known as a **Huffman tree**. This tree is then used to translate messages from text to a compressed binary format and back.

### What is "Coding" in "Huffman Coding"?

In this context, "coding" does not mean programming. It refers to a system for representing information.

  * **Fixed-Length Codes (like ASCII):** Every character takes the same amount of space (e.g., 'A' is `01000001` and 'Z' is `01011010`, both 8 bits). This is simple but inefficient, as rare characters take up the same space as common ones.
  * **Variable-Length Codes (like Huffman):** This algorithm creates an optimal code where common characters get short bit codes (e.g., 'e' might be `01`) and rare characters get long bit codes (e.g., 'z' might be `11101`). This significantly reduces the total size of the data.

Your task is to build the machine that generates and reads this optimal variable-length code.

## Algorithm Principles

### Heap vs. Tree

It is critical not to confuse the two tree-based structures in this assignment:

  * **The Min-Heap:** This is a data structure (which you will build using a `std::vector`) that stores `Node*` pointers. Its only job is to keep the nodes sorted by frequency, so you can always find the one with the *minimum* frequency.
  * **The Huffman Tree:** This is the *final product* that you build *from* the heap. You will pull nodes *out* of the heap to assemble this tree.

### Order of Operations

The autograder will call your functions in a specific order:

1.  A series of `insert_freq` calls will be made.
2.  `print_heap` will be called to check the state of your heap.
3.  `build_tree` will be called *once*.
4.  A series of `decode` calls will be made to test the final tree.

## Functions to Implement

You are responsible for implementing the `TODO` functions in `huffman.cpp`. The heap functions (`heap_insert`, `pop`, etc.) are for you to design and implement. The `print_heap` and `decode_helper` wrapper functions are already provided for you.

-----

### `void build_tree()`

This is the main algorithm for building the Huffman tree from the heap. At this point, your heap is full of leaf nodes, one for each character.

**Algorithm:**

1.  Loop while your heap contains more than one node.
2.  Inside the loop, remove the two nodes that have the lowest frequencies from the heap. These will become the `left` and `right` children of a new node.
3.  Create a new *internal* node that represents the combination of these two. Its frequency should be the sum of its children's frequencies.
4.  Insert this new internal node back into the heap.
5.  This process repeats, combining smaller nodes into larger ones, until only one node remains in the heap. This final node is the `root` of your completed Huffman tree, and you should store it in the `root` member variable.

-----

### `private: void decode(bool* bits, int size)`

This function uses the completed tree to decode a message. The `decode_helper` function has already translated the input string of '0's and '1's into an array of `bool` values for you.

**Algorithm:**
The `bits` array represents a single, continuous path down your tree.

1.  Start at the `root` of your tree.
2.  For each bit in the `bits` array, travel down the tree. A `false` bit ('0') means "go to the left child," and a `true` bit ('1') means "go to the right child."
3.  When your traversal lands on a leaf node (one that holds a character), you have decoded one character. Print it.
4.  After printing, **immediately reset your traversal back to the `root`** to begin decoding the next character, starting from the very next bit in the `bits` array.