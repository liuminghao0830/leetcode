#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return {};
        unordered_map<int, vector<int>> m;
        queue<pair<int, TreeNode*>> q; 
        q.push(make_pair(0, root));
        
        int mn = 0, mx = 0;
        while (!q.empty()){
            auto t = q.front(); q.pop();
            m[t.first].push_back(t.second->val);
            if (t.second->left) q.push(make_pair(t.first - 1, t.second->left));
            if (t.second->right) q.push(make_pair(t.first + 1, t.second->right));
            mn = min(t.first - 1, mn);
            mx = max(t.first + 1, mx);
        }
        vector<vector<int>> res(mx - mn - 1);
        for (auto it : m){
            res[it.first - mn - 1] = it.second;
        }
        return res;
    }
};

int main(){
    return 0;
}