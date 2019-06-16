#include<bits/stdc++.h>

using namespace std;

/*
Given a positive integer n, break it into the sum of at least two 
positive integers and maximize the product of those integers. Return 
the maximum product you can get.

Eg:
Input: 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
*/

class Solution{
public:
    int integerBreak(int n){
        if (n == 2) return 1;
        if (n == 3) return 2;

        int res = 1;

        while (n > 4){
            res *= 3;
            n -= 3;
        }
        
        res *= n == 0 ? 1 : n;
        
        return res;
    }
}; Solution solution;

int main(){
    int n = 9;

    auto res = solution.integerBreak(n);

    cout << res << "\n";

    return 0;
}

