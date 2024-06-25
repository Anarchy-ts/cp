#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both trees are empty
        if (p == nullptr && q == nullptr) {
            return true;
        }
        // If one tree is empty and the other is not
        if (p == nullptr || q == nullptr) {
            return false;
        }
        // If the values of the current nodes are different
        if (p->val != q->val) {
            return false;
        }
        // Recursively check the left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Helper function to create a new TreeNode.
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int main() {
    // Example 1
    TreeNode* p1 = newNode(1);
    p1->left = newNode(2);
    p1->right = newNode(3);

    TreeNode* q1 = newNode(1);
    q1->left = newNode(2);
    q1->right = newNode(3);

    Solution solution;
    cout << boolalpha << solution.isSameTree(p1, q1) << endl; // Expected output: true

    // Example 2
    TreeNode* p2 = newNode(1);
    p2->left = newNode(2);

    TreeNode* q2 = newNode(1);
    q2->right = newNode(2);

    cout << boolalpha << solution.isSameTree(p2, q2) << endl; // Expected output: false

    // Example 3
    TreeNode* p3 = newNode(1);
    p3->left = newNode(2);
    p3->right = newNode(1);

    TreeNode* q3 = newNode(1);
    q3->left = newNode(1);
    q3->right = newNode(2);

    cout << boolalpha << solution.isSameTree(p3, q3) << endl; // Expected output: false

    return 0;
}
