#include<bits/stdc++.h>

using namespace std;

/*
Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, 
not the kth distinct element.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        return nums[k - 1];
    }
}; Solution solution;

int main(){
	vector<int> nums{3, 2, 1, 5, 6, 4};
	int k = 2;

	int res = solution.findKthLargest(nums, k);
	cout << res << endl;

    return 0;
}
