#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
private:
    string dfs(TreeNode* root, unordered_map<string, int>& m, vector<TreeNode*>& res){
        if (root == NULL) return "#";
        string str = to_string(root->val) + "," + 
                    dfs(root->left, m, res) + "," + 
                    dfs(root->right, m, res);
        if (m[str] == 1) res.push_back(root);
        m[str]++;
        return str;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        /* DFS O(n) : 65% */
        unordered_map<string, int> m;
        vector<TreeNode*> res;
        string node = dfs(root, m, res);
        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);
    Solution* solution = new Solution();
    auto res = solution->findDuplicateSubtrees(root);
    
    return 0;
}