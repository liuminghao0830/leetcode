#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*DP O(n) : 86% */
        int hold = -prices[0]; int sold = 0;
        for (int i = 1; i < prices.size(); ++i){
            hold = max(hold, sold - prices[i]);
            sold = max(sold, hold + prices[i] - fee);
        }
        return sold;
    }
};

int main(){
    vector<int> prices{1, 3, 2, 8, 4, 9};
    Solution* solution = new Solution();
    cout << solution->maxProfit(prices, 2) << endl;
    return 0;
}