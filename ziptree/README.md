# Zip Tree Assignment

## Overview

This assignment implements a **zip tree**, a randomized binary search tree data structure that maintains balance through geometric rank assignments and "zip/unzip" operations rather than tree rotations.

### What is a Zip Tree?

A zip tree is a binary search tree where:
- Each node has a **key** (must be unique) and a **rank** (can have duplicates)
- The tree is **max-heap ordered** by ranks, with ties broken in favor of smaller keys
- Ranks follow a **geometric distribution**: a node has rank k with probability 1/2^(k+1)
- Operations use **unzipping** (for insertion) and **zipping** (for deletion) instead of rotations

**Performance**: All operations (search, insert, delete) run in expected O(log n) time.

## Node Structure

```cpp
struct Node {
    int key;        // The value stored (must be unique)
    int rank;       // Random rank for heap ordering
    Node *left;     // Left child pointer
    Node *right;    // Right child pointer
};
```

## Heap Ordering Rules

Your implementation must maintain these invariants:
- `parent.rank > left_child.rank` (strict inequality)
- `parent.rank >= right_child.rank` (allows equality)
- When `parent.rank == right_child.rank`, then `parent.key < right_child.key`

## Functions to Implement

### `void insert_with_rank(int x, int r)`

Insert a new node with key `x` and rank `r` using the **unzip** operation.

**Algorithm**:
1. Search down the tree for key `x`
2. Stop when you find a node `u` where:
   - `u.rank < r`, OR
   - `u.rank == r` AND `u.key < x`
3. **Unzip**: Continue the search, splitting nodes into two paths:
   - Path P: nodes with `key < x` (will become left subtree)
   - Path Q: nodes with `key > x` (will become right subtree)
4. Insert node `x` at position `u`, with P as left child and Q as right child

**Note**: If a node with key `x` already exists, do not insert.

### `void delete_val(int x)`

Delete the node with key `x` using the **zip** operation.

**Algorithm**:
1. Search for node with key `x`
2. If not found, do nothing
3. **Zip**: Merge the left and right subtrees by:
   - Walk down the right spine of the left subtree
   - Walk down the left spine of the right subtree
   - Merge them into a single path R in decreasing rank order
   - Nodes are placed as left/right children based on their keys
4. Replace node `x` with the root of path R

### `bool contains(int x)`

Return `true` if the tree contains a node with key `x`, `false` otherwise.

### `int getdepth(int x)`

Return the depth of the node with key `x` (root has depth 0). Return -1 if not found.