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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        if (root == nullptr) {
            return avg;
        }

        queue<TreeNode*> q;
        q.push(root);
        double sum = 0;
        while (!q.empty()) {
            int level_size = q.size();
            sum = 0;
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                

                // Enqueue the left and right children
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                
                
            }
            avg.push_back(sum/level_size);
        }

        return avg;
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
    TreeNode* root1 = newNode(3);
    root1->left = newNode(9);
    root1->right = newNode(20);
    root1->right->left = newNode(15);
    root1->right->right = newNode(7);

    Solution solution;
    vector<double> rightView1 = solution.averageOfLevels(root1);
    cout << "Right side view of tree 1: ";
    for (auto val : rightView1) {
        cout << val << " ";
    }
    cout << endl;

    // Example 2: [3,9,20,15,7,null,null]
    TreeNode* root2 = newNode(3);
    root2->left = newNode(9);
    root2->right = newNode(20);
    root2->left->left = newNode(15);
    root2->left->right = newNode(7);

    vector<double> rightView2 = solution.averageOfLevels(root2);
    cout << "Right side view of tree 2: ";
    for (auto val : rightView2) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
