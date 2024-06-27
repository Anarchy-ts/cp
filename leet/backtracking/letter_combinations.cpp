#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string currentCombination;
        vector<string> digitToLetters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(0, digits, currentCombination, result, digitToLetters);
        return result;
    }

private:
    void backtrack(int index, const string& digits, string& currentCombination, vector<string>& result, const vector<string>& digitToLetters) {
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }

        int digit = digits[index] - '0';
        const string& letters = digitToLetters[digit];

        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(index + 1, digits, currentCombination, result, digitToLetters);
            currentCombination.pop_back(); // backtrack
        }
    }
};

// Helper function to test the solution with examples
void testSolution(const string& digits) {
    Solution solution;
    vector<string> combinations = solution.letterCombinations(digits);
    cout << "Letter combinations for digits \"" << digits << "\": ";
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;
}

int main() {
    // Example 1
    testSolution("23");

    // Example 2
    testSolution("");

    // Example 3
    testSolution("2");

    return 0;
}
