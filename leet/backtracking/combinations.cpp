#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        backtrack(1, n, k, currentCombination, result);
        return result;
    }

private:
    void backtrack(int start, int n, int k, vector<int>& currentCombination, vector<vector<int>>& result) {
        if (currentCombination.size() == k) {
            result.push_back(currentCombination);
            return;
        }

        for (int i = start; i <= n; ++i) {
            currentCombination.push_back(i);
            backtrack(i + 1, n, k, currentCombination, result);
            currentCombination.pop_back(); // backtrack
        }
    }
};

// Helper function to print the result
void printCombinations(const vector<vector<int>>& combinations) {
    cout << "[";
    for (const auto& combination : combinations) {
        cout << "[";
        for (size_t i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i < combination.size() - 1) cout << ",";
        }
        cout << "]";
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;

    // Example 1
    int n1 = 4, k1 = 2;
    vector<vector<int>> combinations1 = solution.combine(n1, k1);
    cout << "Combinations for n = " << n1 << " and k = " << k1 << ": ";
    printCombinations(combinations1);

    // Example 2
    int n2 = 1, k2 = 1;
    vector<vector<int>> combinations2 = solution.combine(n2, k2);
    cout << "Combinations for n = " << n2 << " and k = " << k2 << ": ";
    printCombinations(combinations2);

    return 0;
}
