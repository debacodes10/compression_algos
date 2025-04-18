#include "huffman.hpp"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <memory>

namespace huffman {

    // Tree node structure
    struct Node {
        char ch;
        int freq;
        Node* left;
        Node* right;

        Node(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
    };

    // Custom comparator for priority queue
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };

    // Recursive function to generate codes
    void generateCodes(Node* root, const std::string& code,
                       std::unordered_map<char, std::string>& huffCodes) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            huffCodes[root->ch] = code;
        }

        generateCodes(root->left, code + "0", huffCodes);
        generateCodes(root->right, code + "1", huffCodes);
    }

    void compress(const std::string& text) {
        if (text.empty()) {
            std::cout << "Input is empty.\n";
            return;
        }

        // Step 1: Count frequency
        std::unordered_map<char, int> freqMap;
        for (char ch : text)
            freqMap[ch]++;

        // Step 2: Push to priority queue
        std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
        for (const auto& pair : freqMap)
            pq.push(new Node(pair.first, pair.second));

        // Step 3: Build Huffman Tree
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();
            Node* merged = new Node('\0', left->freq + right->freq);
            merged->left = left;
            merged->right = right;
            pq.push(merged);
        }

        Node* root = pq.top();

        // Step 4: Generate codes
        std::unordered_map<char, std::string> huffCodes;
        generateCodes(root, "", huffCodes);

        std::cout << "\nHuffman Codes:\n";
        for (const auto& pair : huffCodes) {
            std::cout << pair.first << " : " << pair.second << '\n';
        }

        // Encode the text
        std::string encoded;
        for (char ch : text)
            encoded += huffCodes[ch];

        std::cout << "\nOriginal Text: " << text << '\n';
        std::cout << "Encoded Binary: " << encoded << '\n';
        std::cout << "Original Size: " << text.length() * 8 << " bits\n";
        std::cout << "Compressed Size: " << encoded.length() << " bits\n";
    }

    // Optional: Free memory recursively
    void freeTree(Node* root) {
        if (!root) return;
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }

}
