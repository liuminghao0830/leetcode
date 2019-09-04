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
    int widthOfBinaryTree(TreeNode* root) {
        /* BFS O(n) : 91% */
        queue<TreeNode*> q; q.push(root);
        vector<int> p{1}; int max_width = 0;
        while (!q.empty()){
            max_width = max(max_width, p.back() - p[0] + 1);
            int n = q.size();
            if (n == 1) p[0] = 1;
            vector<int> p2;
            for (int i = 0; i < n; ++i){
                TreeNode* t = q.front(); q.pop();
                if (t->left) {
                    q.push(t->left); 
                    p2.push_back(p[i] * 2);
                }
                if (t->right) {
                    q.push(t->right); 
                    p2.push_back(p[i] * 2 + 1);
                }
            }
            p = p2;
        }
        return max_width;
    }
};

int main(){
    Solution* solution = new Solution();
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    cout << solution->widthOfBinaryTree(root) << endl;
    return 0;
}