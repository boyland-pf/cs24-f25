#include <iostream>
#include <string>
#include <vector> // Note: You may not use std::vector or other containers for your stacks.
#include <sstream>

std::vector<std::string> get_args(const std::string& command) {
    std::vector<std::string> args;
    std::stringstream ss(command);
    std::string arg;
    bool in_quotes = false;
    std::string current_arg;

    for (char c : command) {
        if (c == ' ' && !in_quotes) {
            if (!current_arg.empty()) {
                args.push_back(current_arg);
                current_arg.clear();
            }
        } else if (c == '"') {
            in_quotes = !in_quotes;
        } else {
            current_arg += c;
        }
    }
    if (!current_arg.empty()) {
        args.push_back(current_arg);
    }
    return args;
}

int main() {
    // TODO: Your implementation here

    std::string line;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }
        std::vector<std::string> args = get_args(line);
        std::string command = args[0];

        // Example of how to handle a command
        if (command == "PRINT") {
            // Your print logic here
        }
        // TODO: Handle other commands: CREATE, APPEND, REPLACE, DELETE, UNDO, REDO
    }

    return 0;
}
