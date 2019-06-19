#include<bits/stdc++.h>

using namespace std;

/*
Given a n x n matrix where each of the rows and columns are 
sorted in ascending order, find the kth smallest element in 
the matrix.

Note that it is the kth smallest element in the sorted order, 
not the kth distinct element. 
*/


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(); vector<int> v;
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                v.push_back(matrix[i][j]);
            }
        }
        sort(v.begin(), v.end());
        
        return v[k - 1];
    }
}; Solution solution;

int main(){
	vector<vector<int>> matrix; int k = 8;
	matrix.push_back({1, 5, 9});
	matrix.push_back({10, 11, 13});
	matrix.push_back({12, 13, 15});

	int res = solution.kthSmallest(matrix, k);
	cout << res << endl;

    return 0;
}
