#include<iostream>
#include<vector>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int max_cnt = 0;
    void dfs(TreeNode* root, int pre, int cnt){
        if (!root) { max_cnt = max(max_cnt, cnt); return; }
        if (root->val == pre + 1) cnt++;
        else {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        }
        dfs(root->left, root->val, cnt);
        dfs(root->right, root->val, cnt);
    }
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        dfs(root->left, root->val, 1);
        dfs(root->right, root->val, 1);
        return max_cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(5);
    cout << solution->longestConsecutive(root) << "\n";
    return 0;
}