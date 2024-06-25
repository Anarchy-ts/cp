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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isMirror(root->left, root->right);
    }
    
    bool isMirror(TreeNode* left, TreeNode* right) {
        // If both nodes are nullptr, they are symmetric
        if (left == nullptr && right == nullptr) {
            return true;
        }
        // If one of the nodes is nullptr or their values are different, they are not symmetric
        if (left == nullptr || right == nullptr || left->val != right->val) {
            return false;
        }
        // Recursively check inner subtrees
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
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
    // Example 1: [1,2,2,3,4,4,3]
    TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(2);
    root1->left->left = newNode(3);
    root1->left->right = newNode(4);
    root1->right->left = newNode(4);
    root1->right->right = newNode(3);
    
    Solution solution;
    cout<<solution.isSymmetric(root1)<<endl;

    // Example 2: [1,2,2,null,3,null,3]
    TreeNode* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(2);
    root2->left->right = newNode(3);
    root2->right->right = newNode(3);

    cout<<solution.isSymmetric(root2)<<endl;
    return 0;
}
