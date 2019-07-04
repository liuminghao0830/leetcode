#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int DFS(TreeNode* root, unordered_map<int, int> &m, unordered_set<int> &res, int &cnt){
        if (!root) return 0;
        int left = DFS(root->left, m, res, cnt);
        int right = DFS(root->right, m, res, cnt);
        int sum = root->val + left + right;
        m[sum]++;
        
        if (m[sum] > cnt) {
            res.clear(); 
            res.insert(sum); 
            cnt = m[sum];
        }
        else if (m[sum] == cnt) res.insert(sum);
        
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m;
        unordered_set<int> s; int cnt = 0;
        
        DFS(root, m, s, cnt);
        vector<int> res(s.begin(), s.end());
        
        return res;
    }
}; Solution solution;

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-5);
    vector<int> res = solution.findFrequentTreeSum(root);

    for (auto n : res) cout << n << " ";
    cout << "\n";

    return 0;
}
