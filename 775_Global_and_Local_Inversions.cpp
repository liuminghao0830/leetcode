#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i){
            if (abs(A[i] - i) > 1) return false;
        }
        return true;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> A{1, 2, 0};
    cout << solution->isIdealPermutation(A) << endl;
    vector<int> B{1, 0, 2};
    cout << solution->isIdealPermutation(B) << endl;
    return 0;
}