#include<iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
// time complexity : O(n^2)
private:
    int dfs(TreeNode* root){
        if (!root) return 0;
        return dfs(root->left) + dfs(root->right) + 1;
    }
    bool isBST(TreeNode* root, int mx, int mn){
        if (!root) return true;
        if (root->val >= mx || root->val <= mn) return false;
        return isBST(root->left, root->val, mn) && isBST(root->right, mx, root->val);
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        if (isBST(root, INT_MAX, INT_MIN)) return dfs(root);
        return max(largestBSTSubtree(root->left), largestBSTSubtree(root->right));
    }
};