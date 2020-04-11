#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* t = NULL;
    vector<TreeNode*> dfs(TreeNode* root, TreeNode* p){
        vector<TreeNode*> left, right;
        if (root->left) left = dfs(root->left, p);
        left.push_back(root);
        if (root->right) right = dfs(root->right, p);
        for (auto r : right) left.push_back(r);
        return left;
    }
public:
    TreeNode* inorderSuccessor_dfs(TreeNode* root, TreeNode* p) {
        auto nodes = dfs(root, p);
        for (int i = 1; i < nodes.size(); ++i){
            if (nodes[i - 1]->val == p->val) return nodes[i];
        }
        return NULL;
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> s; t = root;
        bool find = false;
        while (t || !s.empty()){
            while (t){
                s.push(t);
                t = t->left;
            }
            t = s.top(); s.pop();
            if (find && t->val > p->val) return t;
            if (t == p) find = true;
            t = t->right;
        }
        return NULL;
    }
};