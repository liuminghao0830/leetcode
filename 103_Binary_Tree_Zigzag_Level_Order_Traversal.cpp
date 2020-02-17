#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /* O(n) : 87% */
        if (!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q; q.push(root);
        int cnt = 1;
        while (!q.empty()){
            vector<int> row;
            int s = q.size();
            for (int i = 0; i < s; ++i){
                auto t = q.front(); q.pop();
                row.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            if (!(cnt % 2)) row = vector<int>(row.rbegin(), row.rend());
            res.push_back(row);
            cnt++;
        }
        return res;
    }
};


int main(){
    Solution* solution = new Solution();

    TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(17);

    auto res = solution->zigzagLevelOrder(node);
    for (auto row : res){
        for (int n : row) cout << n << " ";
        cout << "\n";
    }
    return 0;
}