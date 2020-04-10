#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
private:
    void recursion(string num, vector<string>& local, 
                                   int s, bool &res){
        if (s >= num.length()) { 
            if (local.size() > 2) res = true; 
            return; 
        }

        for (int i = s; i < num.length(); ++i){
            int len = local.size();
            string n = num.substr(s, i - s + 1);
            if (n.length() > 1 && n[0] == '0' || n.length() > 19) break;
            else if (local.size() >= 2 && stol(n) != stol(local[len - 1]) + stol(local[len - 2])) continue;
            local.push_back(n);
            recursion(num, local, i + 1, res);
            local.pop_back();
        }
    }
public:
    bool isAdditiveNumber(string num) {
        vector<string> local; bool res = false;
        recursion(num, local, 0, res);
        return res;
    }
};


int main(){
    Solution* solution = new Solution();
    string num = "199100199";
    bool res = solution->isAdditiveNumber(num);

    cout << res << endl;

    return 0;
}
