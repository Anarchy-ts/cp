#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_view;
        if (root == nullptr) {
            return right_view;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // If it's the last node in this level, add it to the right view
                if (i == level_size - 1) {
                    right_view.push_back(node->val);
                }

                // Enqueue the left and right children
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
        }

        return right_view;
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
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    // Example 1: [1,2,3,null,5,null,4]
    TreeNode* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->right = newNode(5);
    root1->right->right = newNode(4);

    Solution solution;
    vector<int> rightView1 = solution.rightSideView(root1);
    cout << "Right side view of tree 1: ";
    for (int val : rightView1) {
        cout << val << " ";
    }
    cout << endl;

    // Example 2: [1,null,3]
    TreeNode* root2 = newNode(1);
    root2->right = newNode(3);

    vector<int> rightView2 = solution.rightSideView(root2);
    cout << "Right side view of tree 2: ";
    for (int val : rightView2) {
        cout << val << " ";
    }
    cout << endl;

    // Example 3: []
    TreeNode* root3 = nullptr;

    vector<int> rightView3 = solution.rightSideView(root3);
    cout << "Right side view of tree 3: ";
    for (int val : rightView3) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
