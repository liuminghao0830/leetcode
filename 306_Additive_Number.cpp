#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void helper(string num, vector<long>& seq, int s, bool& res){
        if (res) return;
        if (s >= num.length()) {
            if (seq.size() >= 3) res = true;
            return;
        }

        for (int i = s; i < num.length(); ++i){
            string target = num.substr(s, i - s + 1);
            if ((target.length() > 1 && target[0] == '0') || target.length() > 19) break;
            int n = seq.size(); long int num1 = stol(target);
            if (seq.size() > 1 && num1 != seq[n - 2] + seq[n - 1]) continue;
            seq.push_back(num1);
            helper(num, seq, i + 1, res);
            seq.pop_back();
        }
    }
    bool isAdditiveNumber(string num) {
        vector<long> seq; bool res = false;

        helper(num, seq, 0, res);

        return res;
    }
}; Solution solution;


int main(){
    string num = "199100199";
    bool res = solution.isAdditiveNumber(num);

    cout << res << endl;

    return 0;
}
