# Assignment: The Weighted Undo/Redo Editor

In this assignment, you will implement a simple command-line abstraction of text editing. It will come with an undo + redo mechanism which you should implement using stacks.

## Functional Requirements

Your program, named `undoredo`, will manage a single string. It must read commands from standard input, process them, and print output to standard output. The program should continue processing commands until it reaches the end of the input stream.

## Command Structure

Your program must support the following commands:

### CREATE <max_weight> "<initial_string>"

This will always be the first command. It initializes the editor.

- `<max_weight>` is an integer specifying the maximum total weight the undo stack can hold.
- `<initial_string>` is the starting string, which will be enclosed in double quotes.

**Example:** `CREATE 100 "This is the initial text."`

### APPEND "<string_to_append>"

Appends the given string to the current string.

- The weight of this action is the length of `<string_to_append>`.

**Example:** `APPEND " More text."`

### REPLACE <find_char> <replace_char>

Finds all occurrences of `<find_char>` in the current string and replaces them with `<replace_char>`. Both arguments are single characters.

- The weight of this action is the total number of characters that were replaced.

**Example:** `REPLACE t T`

### DELETE <index>

Deletes all characters from the specified `<index>` to the end of the string. The character at `<index>` is the first to be deleted.

- The weight of this action is the number of characters that were deleted.

**Example:** `DELETE 25`

### UNDO

Reverts the last action. This operation moves the undone action from the undoStack to the redoStack.

- If the undoStack is empty, it should print the error message `Error: Nothing to undo.` followed by a newline.

### REDO

Re-applies the last undone action. This moves the action from the redoStack to the undoStack.

- If the redoStack is empty, it should print the error message `Error: Nothing to redo.` followed by a newline.

### PRINT

Prints the current string to standard output, followed by a newline.

## The Weighted Bounded Undo Stack

This is the core of the assignment.

- **Two Stacks:** You must manage two stacks: an `undoStack` and a `redoStack`.
- **Bounded by Weight:** The `undoStack` does not have a limit on the number of items it can hold, but on the sum of the weights of the items it holds.
- **Pushing a New Action:** When a new action (APPEND, REPLACE, DELETE) is performed:
  - The action and its weight are pushed onto the `undoStack`.
  - The `redoStack` is cleared.
  - If pushing the new action causes the `undoStack`'s total weight to exceed `<max_weight>`, the oldest actions at the bottom of the stack must be removed until the total weight is less than or equal to `<max_weight>`.

## Implementation Details

- You must implement your own Stack data structures. You may not use `std::stack` or any other container from the C++ standard library (like `std::vector`, `std::list`, etc.). Think carefully about what underlying data structure (e.g., a dynamic array, a linked list) is best suited for the undoStack's requirements.
- Your code should be placed in a file named `undoredo.cpp`.
- You must also provide a `Makefile` that compiles your code into an executable named `undoredo`. The `make` command should build the executable, and `make clean` should remove it and any object files.
- Your program should handle quoted strings in commands correctly (e.g., `APPEND "a string with spaces"`).

Good luck!