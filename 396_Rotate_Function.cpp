#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int maxRotateFunction(vector<int>& A){
        if (A.empty()) return 0;
        int n = A.size(); int sum = 0;
        vector<int> f(n);

        for (int s : A) sum += s;
        for (int i = 0; i < n; ++i) f[0] += i * A[i];

        for (int i = 1; i < n; ++i) {
            f[i] = f[i - 1] + sum - n * (long long)A[n - i];
        }

        auto res = max_element(f.begin(), f.end());
        return *res;
    }
}; Solution solution;


int main(){
    vector<int> A{4, 3, 2, 6};
    auto res = solution.maxRotateFunction(A);
    
    cout << res << endl;

    return 0;
}
