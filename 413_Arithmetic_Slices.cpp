#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int cnt = 0;
        int i = 0; int j = 1;
        while (j < A.size()){
            if (A[j] - A[j - 1] == A[i+1] - A[i]) j++;
            else {
                int len = j - i;
                cnt += (len >= 3) ? (len - 1)*(len - 2) / 2 : 0;
                i = j - 1;
                j++;
            }
            if (j == A.size()) {
                int len = j - i;
                cnt += (len >= 3) ? (len - 1)*(len - 2) / 2 : 0;
            }
        }
        
        return cnt;
    }
}; Solution solution;

int main(){
    vector<int> A{1, 2, 3, 4, 5, 7, 9};
    cout << solution.numberOfArithmeticSlices(A) << endl;
    return 0;
}