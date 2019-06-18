#include<bits/stdc++.h>

using namespace std;

/*
Given an array nums containing n + 1 integers where each 
integer is between 1 and n (inclusive), prove that at least 
one duplicate number must exist. Assume that there is only 
one duplicate number, find the duplicate one.
*/

class Solution{
public:
	int findDuplicate(vector<int>& nums){
		int fast = 0; int slow = 0; int temp = 0;
		while (true){
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) break;
		}
		while (true){
			temp = nums[temp];
			slow = nums[slow];
			if (temp == slow) break;
		}

		return slow;
	}	
}; Solution solution;


int main(){
	vector<int> nums{1, 3, 4, 2, 2};
	int res = solution.findDuplicate(nums);

	cout << res << endl;

    return 0;
}
