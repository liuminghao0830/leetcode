#include<bits/stdc++.h>

using namespace std;

/*
Given a non negative integer number num. For every numbers i 
in the range 0 ≤ i ≤ num calculate the number of 1's in their 
binary representation and return them as an array.
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        for (int i = 1; i <= num; ++i){
            if (i % 2 == 0) dp[i] = dp[i / 2];
            else dp[i] = dp[i / 2] + 1;
        }
        return dp;
    }
}; Solution solution;


int main(){
	vector<int> res = solution.countBits(5);
	for (int n : res) cout << n << " ";
	cout << "\n";

    return 0;
}
