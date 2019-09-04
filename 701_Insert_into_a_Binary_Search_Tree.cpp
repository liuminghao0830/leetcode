#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        /* DFS O(n) : 98% */
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        else if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Solution* solution = new Solution();
    auto res = solution->insertIntoBST(root, 5);
    queue<TreeNode*> q; q.push(res);
    while (!q.empty()){
        for (int i = q.size(); i > 0; --i){
            TreeNode* t = q.front(); q.pop();
            cout << t->val << " ";
            if (t->left) q.push(t->left); 
            if (t->right) q.push(t->right);
        }
        cout << "\n";
    }
    return 0;
    return 0;
}