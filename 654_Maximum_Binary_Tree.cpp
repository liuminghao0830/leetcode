#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution{
private:
    TreeNode* dfs(vector<int>& nums, int s, int e){
        if (s < 0 || e > nums.size() || s >= e) return NULL;
        auto mx = max_element(nums.begin() + s, nums.begin() + e);
        TreeNode* root = new TreeNode(*mx);
        root->left = dfs(nums, s, mx - nums.begin());
        root->right = dfs(nums, mx - nums.begin() + 1, e);
        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        /* DFS O(nlogn) : 89% */
        TreeNode* root = dfs(nums, 0, nums.size());
        return root;
    }
};

int main(){
    vector<int> nums{3, 2, 1, 6, 0, 5};
    Solution* solution = new Solution();
    auto root = solution->constructMaximumBinaryTree(nums);
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()){
        for (int i = q.size(); i > 0; --i){
            auto t = q.front(); q.pop();
            cout << t->val << " ";
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
        cout << "\n";
    }
    return 0;
}