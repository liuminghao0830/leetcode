#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        /* O(n): 56% */
        int left = 1, right = n;
        vector<int> res;
        while (left <= right){
            if (k > 1 && k % 2){
                res.push_back(left++);
                k--;
            }
            else if (k > 1 && k % 2 == 0){
                res.push_back(right--); 
                k--;
            }
            else res.push_back(left++);
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    auto res = solution->constructArray(5, 2);
    for (auto n : res) cout << n << " ";
    cout << "\n";
    return 0;
}