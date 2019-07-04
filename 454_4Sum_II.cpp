#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size(); int cnt = 0;
        unordered_map<int, int> m;
        
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                m[A[i] + B[j]]++;
            }
        }
        for (int k = 0; k < n; ++k){
            for (int l = 0; l < n; ++l){
                int target = -C[k] - D[l];
                if (m.count(target)) cnt += m[target];
            }
        }
        
        return cnt;
    }
}; Solution solution;

int main(){
    vector<int> A{1, 2}; vector<int> B{-2, -1};
    vector<int> C{-1, 2}; vector<int> D{-1, 2};
    int res = solution.fourSumCount(A, B, C, D);
    cout << res << endl;
    return 0;
}
