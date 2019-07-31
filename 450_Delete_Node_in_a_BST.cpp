#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        /* DFS O(height): 94% */
        if (!root) return NULL;
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else {
            if (!root->right || !root->left) {
                root = root->left ? root->left : root->right;
            }
            else {
                TreeNode* mn = root->right;
                while (mn->left) mn = mn->left;
                root->val = mn->val;
                root->right = deleteNode(root->right, mn->val);
            }
        }
        
        return root;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    return 0;
}