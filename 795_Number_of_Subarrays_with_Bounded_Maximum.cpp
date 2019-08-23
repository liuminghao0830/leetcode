#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        /* O(n^2) : 18% */
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i){
            if (A[i] > R) continue;
            int mx = INT_MIN;
            for (int j = i; j < A.size(); ++j){
                mx = max(mx, A[j]);
                if (mx > R) break;
                else if (mx >= L) cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> A{2, 1, 4, 3};
    cout << solution->numSubarrayBoundedMax(A, 2, 3) << endl;
    return 0;
}