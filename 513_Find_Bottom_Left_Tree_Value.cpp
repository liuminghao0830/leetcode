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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        int res;
        while (!q.empty()){
            int s = q.size();
            for (int i = 0; i < s; ++i){
                auto t = q.front(); q.pop();
                if (i == 0) res = t->val;
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    cout << solution.findBottomLeftValue(root) << endl;
    return 0;
}