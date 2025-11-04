#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

struct Node {
    int key;
    int rank;
    Node *left, *right;

    Node(int k, int r) : key(k), rank(r), left(nullptr), right(nullptr) {}
};

class ZipTree {
private:
    Node* root;
    int getRandomRank() {
        int rank = 0;
        // Keep flipping "heads" (rand() % 2 == 1)
        while (rand() % 2 == 1) {
            rank++;
        }
        return rank;
    }

    // Add your own private helper functions here.

public:
    ZipTree() : root(nullptr) {
        // Seed the random number generator once.
        srand(static_cast<unsigned int>(time(nullptr)));
    }

    // Functions for you to implement:

    void insert(int x) {
        int rank = getRandomRank();
        insert_with_rank(x, rank);
    }

    // Insert key x with a specified rank r.
    void insert_with_rank(int x, int r) {
        // TODO
    }

    // Delete the node with value x.
    void delete_val(int x) {
      // TODO
    }

    // Determine whether the tree contains x.
    bool contains(int x) {
      // TODO
    }

    void printcontains(int x) {
      if contains(x){
        std::cout <<"true" << std::endl;
      }
      else {
        std::cout << "false" << std::endl;
      }
    }

    // Finds the depth of the node x in the tree.
    // If it's not in the tree, then return -1.
    int getdepth(int x) {
        // TODO
    }

    void printdepth(int x) {
      std::cout << getdepth(x) << std::endl;
    }

};

// You do not need to modify this section.

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
    ZipTree tree;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty() || line[0] == '#') continue;
        std::vector<std::string> args = get_args(line);
        if (args.empty()) continue;
        
        const std::string& command = args[0];

        try {
            if (command == "insert" && args.size() == 2) {
                tree.insert(std::stoi(args[1]));
            } else if (command == "insert_with_rank" && args.size() == 3) {
                tree.insert_with_rank(std::stoi(args[1]), std::stoi(args[2]));
            } else if (command == "delete" && args.size() == 2) {
                tree.delete_val(std::stoi(args[1]));
            } else if (command == "contains" && args.size() == 2) {
                tree.printcontains(std::stoi(args[1]));
            } else if (command == "getdepth" && args.size() == 2) {
                tree.printdepth(std::stoi(args[1]));
            } else {
                std::cout << "Error: Unknown command or incorrect arguments." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: Invalid argument." << std::endl;
        }
    }
    return 0;
}

