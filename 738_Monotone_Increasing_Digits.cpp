#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int monotoneIncreasingDigits(int N) {
        string str = to_string(N); 
        int n = str.length(), s = n;
        for (int i = n - 1; i > 0; --i){
            if (str[i] >= str[i - 1]) continue;
            str[i - 1]--; s = i;
        }
        for (int j = s; j < n; ++j){
            str[j] = '9';
        }
        return stoi(str);
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->monotoneIncreasingDigits(332) << endl;
    cout << solution->monotoneIncreasingDigits(10) << endl;
    cout << solution->monotoneIncreasingDigits(1234) << endl;
    return 0;
}