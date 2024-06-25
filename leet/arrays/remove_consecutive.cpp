#include <iostream>
#include <string>

std::string removeConsecutiveDuplicates(std::string S) {
    if (S.length() <= 1) {
        return S;
    }

    // Initialize the position to keep track of unique characters
    int pos = 1;

    // Iterate through the string starting from the second character
    for (int i = 1; i < S.length(); ++i) {
        // Only update the position if the current character is different from the previous one
        if (S[i] != S[i - 1]) {
            S[pos] = S[i];
            pos++;
        }
    }

    // Resize the string to include only the unique characters
    S.resize(pos);
    return S;
}

int main() {
    std::string S1 = "aabb";
    std::string S2 = "aabaa";
    std::cout << removeConsecutiveDuplicates(S1) << std::endl;  // Output: "ab"
    std::cout << removeConsecutiveDuplicates(S2) << std::endl;  // Output: "aba"
    return 0;
}
