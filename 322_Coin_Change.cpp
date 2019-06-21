#include<bits/stdc++.h>

using namespace std;

/*
You are given coins of different denominations and a total 
amount of money amount. Write a function to compute the fewest 
number of coins that you need to make up that amount. If that 
amount of money cannot be made up by any combination of the 
coins, return -1
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX); dp[0] = 0;
        sort(coins.begin(), coins.end());
        
        for (int i = coins[0]; i <= amount; ++i){
            for (int c : coins){
                if ((i - c >=0) && dp[i - c] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }
        
        return dp.back()==INT_MAX ?  -1 : dp.back();
    }
}; Solution solution;


int main(){
    vector<int> coins{1, 2, 5};
    int amount = 11;
    int res = solution.coinChange(coins, amount);

    cout << res << endl;

    return 0;
}
