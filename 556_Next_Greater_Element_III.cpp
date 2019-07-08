#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n); int len = num.length();
        int i = len - 1;
        while (i >= 0 && num[i] <= num[i - 1]) i--;
        if (i <= 0) return -1;
        
        int j = len - 1;
        while (j > i - 1 && num[j] <= num[i - 1]) j--;
        
        swap(num[i - 1], num[j]);
        sort(num.begin() + i, num.end());
        
        return stol(num) > INT_MAX ? -1 : stol(num);
    }
};

int main(){
    Solution* solution = new Solution();
    int n = 1234;
    cout << solution->nextGreaterElement(n) << endl;

    return 0;
}