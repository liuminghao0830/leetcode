#include<iostream>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

class Solution{
public:
    bool verifyPreorder2(vector<int>& preorder) {
        // time O(n), space O(1)
        int mn = INT_MIN, i = -1;
        for (int val : preorder){
            if (val < mn) return false;
            while (i >= 0 && val > preorder[i]){
                mn = preorder[i--];
            }
            preorder[++i] = val;
        }
        return true;
    }
    bool verifyPreorder(vector<int>& preorder) {
        // time O(n), space O(n)
        stack<int> s; int mn = INT_MIN;
        for (int val : preorder){
            if (val < mn) return false;
            while (!s.empty() && val > s.top()){
                mn = s.top(); s.pop();
            }
            s.push(val);
        }
        return true;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> nums1{5, 2, 6, 1, 3}, nums2{5, 2, 3, 3, 6};
    cout << solution->verifyPreorder(nums1) << "\n";
    cout << solution->verifyPreorder(nums2) << "\n";
    return 0;
}