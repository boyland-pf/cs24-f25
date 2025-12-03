#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class CuckooHashTable {
private:
    std::vector<std::string> table1;
    std::vector<std::string> table2;
    size_t size;

    // Helper to get a hash for the first table
    size_t hash1(const std::string& key) {
        size_t h = 0;
        for (char c : key) {
            h = (h * 31 + c) % size;
        }
        return h;
    }

    // Helper to get a hash for the second table
    size_t hash2(const std::string& key) {
        size_t h = 0;
        for (char c : key) {
            h = (h * 37 + c) % size; // Different multiplier/logic
        }
        return h;
    }

    void rehash() {
        // TODO:
        // 1. Store all existing keys from table1 and table2.
        // 2. Double the size variable.
        // 3. Resize and clear table1 and table2.
        // 4. Re-insert all stored keys.
    }

public:
    CuckooHashTable(size_t s) : size(s) {
        table1.resize(size, "");
        table2.resize(size, "");
    }

    void insert(const std::string& key) {
        // TODO: Implement Cuckoo insertion
        // 1. Try to place in table1.
        // 2. If occupied, evict and move victim to table2.
        // 3. Repeat until empty spot found.
        // 4. If number of kicks > size, call rehash() and try again.
    }

    bool lookup(const std::string& key) {
        // TODO: Check both tables
        return false; 
    }

    void delete_key(const std::string& key) {
        // TODO: Remove from whichever table contains it
    }
};

std::vector<std::string> get_args(const std::string& line) {
    std::vector<std::string> args;
    std::stringstream ss(line);
    std::string arg;
    while (ss >> arg) {
        args.push_back(arg);
    }
    return args;
}

int main() {
    // Pointer used to allow delayed initialization
    CuckooHashTable* ht = nullptr;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::vector<std::string> args = get_args(line);
        if (args.empty()) continue;

        const std::string& command = args[0];

        try {
            if (command == "CREATE" && args.size() == 2) {
                if (ht) delete ht;
                ht = new CuckooHashTable(std::stoi(args[1]));
            } else if (command == "INSERT" && args.size() == 2) {
                if (ht) {
                    ht->insert(args[1]);
                }
            } else if (command == "LOOKUP" && args.size() == 2) {
                if (ht) {
                    if (ht->lookup(args[1])) std::cout << "true" << std::endl;
                    else std::cout << "false" << std::endl;
                }
            } else if (command == "DELETE" && args.size() == 2) {
                if (ht) ht->delete_key(args[1]);
            } else {
                std::cout << "Error: Unknown command or incorrect arguments." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: Invalid argument." << std::endl;
        }
    }
    
    if (ht) delete ht;
    return 0;
}