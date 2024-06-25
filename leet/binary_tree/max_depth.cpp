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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
           return 0;
        return 1+ max(maxDepth(root->left),maxDepth(root->right));   
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
    // Create the binary tree: [3,9,20,null,null,15,7]
    TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    Solution solution;
    // Calculate and print the maximum depth of the tree.
    cout << "Maximum depth: " << solution.maxDepth(root) << endl; // Expected output: 3

    // Example 2: [1, null, 2]
    TreeNode* root2 = newNode(1);
    root2->right = newNode(2);
    cout << "Maximum depth: " << solution.maxDepth(root2) << endl; // Expected output: 2

    return 0;
}
