#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        /* BFS O(n) : 86% */
        if (d == 1) {
            TreeNode* new_root = new TreeNode(v);
            new_root->left = root;
            return new_root;
        }
        queue<TreeNode*> q; q.push(root);
        int depth = 1;
        while (!q.empty()){
            for (int i = q.size(); i > 0; --i){
                TreeNode* t = q.front(); q.pop();
                if (depth == d - 1){
                    TreeNode* l = t->left;
                    TreeNode* r = t->right;
                    t->left = new TreeNode(v); 
                    t->left->left = l;
                    t->right = new TreeNode(v); 
                    t->right->right = r;
                }
                if (t->left) q.push(t->left); 
                if (t->right) q.push(t->right);
            }
            if (depth == d - 1) break;
            depth++;
        }
        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(1);
    root->right->left = new TreeNode(5);
    Solution* solution = new Solution();
    TreeNode* root1 = solution->addOneRow(root, 1, 2);
    queue<TreeNode*> q; q.push(root1);
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
}