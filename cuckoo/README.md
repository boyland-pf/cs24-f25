# Cuckoo Hashing Assignment

## Overview

In this assignment, you will implement **Cuckoo Hashing**, a technique for resolving hash collisions that guarantees $O(1)$ worst-case lookup time.

Most hash tables (like those using chaining or linear probing) have good *average* performance, but collisions can degrade performance to $O(n)$ in the worst case. Cuckoo hashing solves this by using two hash functions and two possible locations for every key. If a collision occurs during insertion, the existing element is evicted (kicked out) and moved to its alternative location, potentially triggering a chain reaction of evictions.

### What's the name from?

The name comes from the behavior of the Cuckoo bird. Some species of Cuckoo are brood parasites; they lay their eggs in the nests of other birds. When the Cuckoo egg hatches, it often kicks the other eggs (or nestlings) out of the nest to claim the space for itself.

In our hash table, inserting a new key might "kick out" an existing key to a different location.

## How It Works

You will maintain two tables, $T_1$ and $T_2$, each of size $S$. You will also use two independent hash functions, $h_1(x)$ and $h_2(x)$.

### Lookup
To check if a key $x$ is in the table, you only need to check two specific locations:
1. $T_1[h_1(x)]$
2. $T_2[h_2(x)]$

If $x$ is not at either of these two spots, it is not in the table. This is why lookup is strictly $O(1)$.

### Deletion
Similar to lookup, check the two possible locations. If found, remove it.

### Insertion
Insertion is the complex part of the structure. To insert key $x$:

1. Check if $T_1[h_1(x)]$ is empty. If yes, place $x$ there.
2. If $T_1[h_1(x)]$ is occupied by some key $y$:
   - Kick $y$ out.
   - Place $x$ in $T_1[h_1(x)]$.
   - Now you must re-insert the evictee $y$ into its *other* potential location. If $y$ was in $T_1$, try to put it in $T_2[h_2(y)]$.
3. If that new location is also occupied (say, by $z$), kick $z$ out and move it to *its* alternative location.
4. Repeat this process until a key lands in an empty spot.

### Cycles and Resizing
It is possible to get into an infinite loop of evictions (e.g., $x$ kicks $y$, $y$ kicks $z$, $z$ kicks $x$).

- Keep a count of the number of evictions in a single insertion.
- If the count exceeds the current size of the tables ($S$), assume a cycle has occurred.
- **Double the capacity** of the tables (update $S$ to $2 \times S$).
- **Rehash everything**: Clear the tables and re-insert all old keys, plus the new key, into the newly resized tables.

## Functional Requirements

Your program `cuckoo` will read commands from standard input.

### CREATE <size>

Initializes the hash tables.
- `<size>` is the size of each of the two tables ($T_1$ and $T_2$).

### INSERT <string>

Inserts the string into the table using the algorithm described above.
- If a cycle is detected, automatically resize and rehash. Do not print an error message for cycles.

### DELETE <string>

Deletes the string from the table.

### LOOKUP <string>

Checks if the string exists in the table.
- Prints `true` if found, `false` otherwise.
