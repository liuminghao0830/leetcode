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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q; q.push(root);
        vector<int> res;
        while (!q.empty()){
            int s = q.size(); int max_val = INT_MIN;
            for (int i = 0; i < s; ++i){
                auto t = q.front(); q.pop();
                max_val = max(max_val, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(max_val);
        }
        return res;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    auto res = solution.largestValues(root);
    
    for (auto n : res) cout << n << " ";
    cout << "\n";
    
    return 0;
}