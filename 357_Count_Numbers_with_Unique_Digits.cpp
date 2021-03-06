#include<bits/stdc++.h>

using namespace std;

/*
Given a non-negative integer n, 
count all numbers with unique digits, x, where 0 ≤ x < 10^n.

Eg:
Input: 2
Output: 91 
Explanation: The answer should be the total numbers in the range 
			 of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
*/

class Solution{
public:
    int countNumbersWithUniqueDigits(int n){
        if (n == 0) return 1;
        if (n == 1) return 10;

        vector<int> dp(n + 1, 0); 
        dp[0] = 1; dp[1] = 10;

        for (int d = 2; d <= n; ++d) {
            dp[d] = 9;
            for (int i = 2; i <= d; ++i) {
                dp[d] *= 9 - i + 2;
            }
            dp[d] += dp[d - 1];
        }
        
        return dp.back();
    }

}; Solution solution;


int main(){
    int n = 2;
    auto res = solution.countNumbersWithUniqueDigits(n);

    cout << res << "\n";

    return 0;
}