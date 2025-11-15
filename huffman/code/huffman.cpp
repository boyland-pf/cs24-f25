#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

//This is the node for the Huffman Tree that you will build.
//Note that the marker for the node being internal is whether its data is '\0' or a real character.
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}

    Node(int f) : data('\0'), freq(f), left(nullptr), right(nullptr) {}
};

class HuffmanTree {

private:

    Node* root;

    // We will use vector here so you don't have to reimplement dynamic array again.
    std::vector<Node*> heap;

    void bubble_up(int index) {
        // TODO
        // Compare the node at 'index' with its parent.
        // If it's smaller, swap them and continue bubbling up.
    }

    void bubble_down(int index) {
        // TODO
        // Compare the node at 'index' with its children.
        // If it's larger than the smaller child, swap them
        // and continue bubbling down.
    }

    void heap_insert(Node* node) {
        // TODO
    }

    Node* pop() {
        // TODO
    }


public:
    HuffmanTree() : root(nullptr) {}

    // Inserts a new frequency into the heap. Cannot be called after the tree has been built.
    void insert_freq(char c, int freq) {
      //TODO
    }

    void print_heap() {
        if (heap.empty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }

        for (size_t i = 0; i < heap.size(); ++i) {
            std::cout << "(";
            if (heap[i]->data == '\0') {
                std::cout << "internal";
            } else {
                std::cout << heap[i]->data;
            }
            std::cout << ":" << heap[i]->freq << ")";
            
            if (i < heap.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }

    // Called once, and builds the code.
    void build_tree() {
      // TODO
    }

    // Called after the tree has been built, to decode a series of bits.
    void decode(bool* bits, int size) {
      // TODO
    }

    void decode_helper(const std::string& bitstring) {
        int n = bitstring.length();
        if (n == 0) {
            return; // Nothing to decode
        }
        bool* boolArray = new bool[n];
        for (int i = 0; i < n; ++i) {
            boolArray[i] = (bitstring[i] == '1');
        }
        decode(boolArray, n);
        delete[] boolArray;
    }

};


//You won't need to change anything past here.

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
    HuffmanTree tree;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty() || line[0] == '#') continue; // Skip comments/empty lines
        std::vector<std::string> args = get_args(line);
        if (args.empty()) continue;
        
        const std::string& command = args[0];

        try {
            if (command == "insert_freq" && args.size() == 3) {
                if (args[1].length() != 1) {
                    std::cout << "Error: Character must be a single character." << std::endl;
                } else {
                    tree.insert_freq(args[1][0], std::stoi(args[2]));
                }
            } else if (command == "print_heap" && args.size() == 1) {
                tree.print_heap();
            } else if (command == "build_tree" && args.size() == 1) {
                tree.build_tree();
            } else if (command == "decode" && args.size() == 2) {
                tree.decode_helper(args[1]);
            } else {
                std::cout << "Error: Unknown command or incorrect arguments." << std::endl;
            }
        } catch (const std::exception& e) {
            // Handle errors from std::stoi if input is not a number
            std::cout << "Error: Invalid argument." << std::endl;
        }
    }
    return 0;
}