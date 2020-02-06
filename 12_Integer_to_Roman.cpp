#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // O(n) : beat 77%
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";
        for (int i = 0; i < nums.size(); ++i){
            while (num >= nums[i]){
                num -= nums[i];
                res += roman[i];
            }
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->intToRoman(3) << "\n";
    return 0;
}