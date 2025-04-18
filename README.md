# 🔐 Data Compression Algorithms: Huffman vs Arithmetic Coding

This project demonstrates and compares two powerful data compression techniques:

- **Huffman Coding**: A greedy algorithm that assigns variable-length binary codes to characters based on frequency.
- **Arithmetic Coding**: A range-based encoding method that represents the entire message as a single floating-point number between 0 and 1.

📚 This project was built as part of a Design and Analysis of Algorithms course.

---

## 💡 Features

- Encode any input text using **Huffman** or **Arithmetic** compression
- View character frequencies, encoding steps, and final compressed outputs
- Compare space savings between both methods
- All implemented in **C++**, from scratch — no external libraries

---

## 📁 Directory Structure
```text
project-root/
├── include/
│   ├── huffman.hpp         # Huffman header
│   └── arithmetic.hpp      # Arithmetic header
├── src/
│   ├── main.cpp            # Entry point with menu
│   ├── huffman.cpp         # Huffman logic
│   └── arithmetic.cpp      # Arithmetic logic
├── build/                  # Output binary
└── README.md               # This file
```

---

## 🚀 Getting Started

### 🔧 Compilation

Use the following `g++` command:

```bash
g++ src/main.cpp src/huffman.cpp src/arithmetic.cpp -Iinclude -o build/compressor
```

### Run the program
```bash
./build/compressor
```

## Sample Run
=== Data Compression Tool ===
Enter the text to compress: ABAB

Choose Compression Algorithm:
1. Huffman Coding
2. Arithmetic Coding
Enter choice (1 or 2): 1

--- Huffman Compression ---
Character Frequencies:
A : 2
B : 2

Huffman Codes:
A : 0
B : 1

Encoded Text: 0101
Original Size: 32 bits
Compressed Size: 4 bits

## Credits
Created by Debadyuti Mukherjee as part of the Design and Analysis Algorithms (DAA) mini project.
