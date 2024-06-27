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
    int preindex=0;
    TreeNode* contree(vector<int>& preorder, vector<int>& inorder,int is,int ie){
       if(is>ie){
        return NULL;
       }
       int inindex;
       TreeNode*root=new TreeNode(preorder[preindex++]);
       for(int i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                inindex=i;
                cout<<inindex<<endl;
                break;
            }
        }
       root->left=contree(preorder,inorder,is,inindex-1); 
       root->right=contree(preorder,inorder,inindex+1,ie); 
       return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        int n=preorder.size()-1;
        return contree(preorder,inorder,i,n);
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
    // Example 1: [3,9,20,15,7]
    TreeNode* root1 = newNode(3);
    root1->left = newNode(9);
    root1->right = newNode(20);
    root1->left->left = newNode(15);
    root1->left->right = newNode(7);
    
     // Example 2: [2,1,3]
    TreeNode* root2 = newNode(9);
    root2->left = newNode(3);
    root2->right = newNode(15);

    Solution solution;
    TreeNode* invertedRoot1 = solution.buildTree(root1,);
    cout << "Inverted tree 1: ";
    printTree(invertedRoot1); // Expected output: 4 7 9 6 2 3 1
    cout << endl;

   


    // Example 3: []
    TreeNode* root3 = nullptr;

    TreeNode* invertedRoot3 = solution.invertTree(root3);
    cout << "Inverted tree 3: ";
    printTree(invertedRoot3); // Expected output: (nothing)
    cout << endl;

    return 0;
}