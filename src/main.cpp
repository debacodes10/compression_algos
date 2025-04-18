#include <iostream>
#include <string>
#include "huffman.hpp"
#include "arithmetic.hpp"

int main() {
    std::string input;
    int choice;

    std::cout << "=== Data Compression Tool ===\n";
    std::cout << "Enter the text to compress: ";
    std::getline(std::cin, input);

    std::cout << "\nChoose Compression Algorithm:\n";
    std::cout << "1. Huffman Coding\n";
    std::cout << "2. Arithmetic Coding\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> choice;

    std::cin.ignore(); // Clear newline from input buffer

    switch (choice) {
        case 1:
            std::cout << "\n--- Huffman Compression ---\n";
            huffman::compress(input);
            break;
        case 2:
            std::cout << "\n--- Arithmetic Compression ---\n";
            arithmetic::compress(input);
            break;
        default:
            std::cout << "Invalid choice. Exiting...\n";
            break;
    }

    return 0;
}
