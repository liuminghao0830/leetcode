#include<iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        TreeNode *left = root->left, *right = root->right;
        TreeNode* r = upsideDownBinaryTree(root->left);

        left->right = root;
        left->left = right;
        root->left = NULL;
        root->right = NULL;
        return r;
    }
};

int main(){
    return 0;
}