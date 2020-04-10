#include<iostream>
#include<vector>

class NumArray {
private:
    vector<int> _nums;
public:
    NumArray(vector<int>& nums) { _nums = nums; }
    
    void update(int i, int val) { _nums[i] = val; }
    
    int sumRange(int i, int j) {
        int cnt = 0;
        for (int s = i; s <= j; ++s) cnt += _nums[s];
        return cnt;
    }
};