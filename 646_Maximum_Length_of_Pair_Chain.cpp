#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        /* DP : O(n^2) : 21% */
        int n = pairs.size(); int cnt = 0;
        vector<int> dp(n, 1);
        
        sort(pairs.begin(), pairs.end());

        for (int i = 1; i < n; ++i){
            for (int j = 0; j < i; ++j){
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
                cnt = max(cnt, dp[i]);
            }
        }
        return cnt;
    }

    int findLongestChain2(vector<vector<int>>& pairs) {
        /* O(nlogn) : 70% */
        int n = pairs.size(); int cnt = 0;
        sort(pairs.begin(), pairs.end());
        int end = pairs[0][1];
        for (int i = 1; i < n; ++i){
            if (pairs[i][0] <= end){
                cnt++;
                end = min(end, pairs[i][1]);
            }
            else end = pairs[i][1];
        }
        return pairs.size() - cnt;
    }
};

int main(){
    vector<vector<int>> pairs{{-10, -8}, {8, 9}, {-5, 0}, {6, 10}, {-6, -4}, {1, 7}, {9, 10}, {-4, 7}};
    Solution* solution = new Solution();
    cout << solution->findLongestChain2(pairs) << endl;
    return 0;
}