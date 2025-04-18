#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <string>

namespace huffman {
    void compress(const std::string& text);
    void decompress(const std::string& encodedText); // Optional
}

#endif // HUFFMAN_HPP
