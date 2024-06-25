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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        // Swap the left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};

// Helper function to create a new TreeNode.
TreeNode* newNode(int val) {
    TreeNode* node = new TreeNode(val);
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Helper function to print a binary tree in level order
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Example 1: [4,2,7,1,3,6,9]
    TreeNode* root1 = newNode(4);
    root1->left = newNode(2);
    root1->right = newNode(7);
    root1->left->left = newNode(1);
    root1->left->right = newNode(3);
    root1->right->left = newNode(6);
    root1->right->right = newNode(9);
    
    Solution solution;
    TreeNode* invertedRoot1 = solution.invertTree(root1);
    cout << "Inverted tree 1: ";
    printTree(invertedRoot1); // Expected output: 4 7 9 6 2 3 1
    cout << endl;

    // Example 2: [2,1,3]
    TreeNode* root2 = newNode(2);
    root2->left = newNode(1);
    root2->right = newNode(3);

    TreeNode* invertedRoot2 = solution.invertTree(root2);
    cout << "Inverted tree 2: ";
    printTree(invertedRoot2); // Expected output: 2 3 1
    cout << endl;

    // Example 3: []
    TreeNode* root3 = nullptr;

    TreeNode* invertedRoot3 = solution.invertTree(root3);
    cout << "Inverted tree 3: ";
    printTree(invertedRoot3); // Expected output: (nothing)
    cout << endl;

    return 0;
}
