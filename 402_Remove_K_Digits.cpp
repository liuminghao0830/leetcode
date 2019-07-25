#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    string removeKdigits(string num, int k) {
        string res = ""; int n = k;
        for (auto c : num){
            if (!n || res.empty()) res += c;
            else {
                while (res.back() > c && n > 0){
                    res.pop_back();
                    n--;
                }
                res += c;
            }
        }
        res.resize(num.size() - k);
        while (res[0] == '0') res.erase(res.begin());
        return res.empty() ? "0" : res;
    }
};

int main(){
    Solution* solution = new Solution();
    string num = "10200";
    cout << solution->removeKdigits(num, 1) << endl;
    return 0;
}