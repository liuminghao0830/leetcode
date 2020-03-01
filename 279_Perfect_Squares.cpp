#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution{
public:
	int minSquares(int n){
		vector<int> dp(n + 1, INT_MAX); dp[0] = 0;
		for (int i = 0; i <= n; ++i){
			for (int j = 1; i + j*j <= n; ++j){
				dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
			}
		}
		return dp[n];
	}
};

int main(){
	Solution* solution = new Solution();
	cout << solution->minSquares(12) << "\n";
	cout << solution->minSquares(13) << "\n";
	return 0;
}