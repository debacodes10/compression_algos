#include "arithmetic.hpp"
#include <iostream>
#include <map>
#include <iomanip>

namespace arithmetic {

    void compress(const std::string& text) {
        if (text.empty()) {
            std::cout << "Input is empty.\n";
            return;
        }

        std::map<char, double> freq;
        for (char ch : text) freq[ch]++;

        // Step 1: Calculate probabilities
        int n = text.size();
        std::map<char, double> prob;
        for (const auto& [ch, count] : freq) {
            prob[ch] = count / n;
        }

        // Step 2: Create cumulative range
        std::map<char, std::pair<double, double>> range;
        double cumulative = 0.0;
        for (const auto& [ch, p] : prob) {
            range[ch] = {cumulative, cumulative + p};
            cumulative += p;
        }

        // Display ranges
        std::cout << "\nCharacter Ranges:\n";
        for (const auto& [ch, r] : range) {
            std::cout << ch << " : [" << r.first << ", " << r.second << ")\n";
        }

        // Step 3: Encode
        double low = 0.0, high = 1.0;
        for (char ch : text) {
            double rangeLow = range[ch].first;
            double rangeHigh = range[ch].second;

            double diff = high - low;
            high = low + diff * rangeHigh;
            low = low + diff * rangeLow;
        }

        // Step 4: Choose any number in [low, high] as code (midpoint is simple)
        double code = (low + high) / 2;

        std::cout << std::fixed << std::setprecision(10);
        std::cout << "\nCompressed Code: " << code << '\n';
        std::cout << "Original Size: " << n * 8 << " bits\n";
        std::cout << "Compressed Size (float): ~" << sizeof(code) * 8 << " bits\n";
    }
}
