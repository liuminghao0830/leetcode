#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    string reorganizeString(string s){
        int n = s.length();
        if (n <= 1) return s;
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
            if (cnt[c - 'a'] > (n + 1) / 2) return "";
        }
        priority_queue<pair<int, char>> q;
        for (char c = 'a'; c <= 'z'; ++c){
            if (cnt[c - 'a']){
                q.push({cnt[c - 'a'], c});
            }
        }
        string res = "";
        while (q.size() >= 2){
            auto t1 = q.top(); q.pop();
            auto t2 = q.top(); q.pop();
            res += t1.second; res += t2.second;
            if (--t1.first > 0) q.push(t1);
            if (--t2.first > 0) q.push(t2);
        }
        if (q.size() > 0) res += q.top().second;
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->reorganizeString("aab") << endl;
    cout << solution->reorganizeString("zhmyo") << endl;
    return 0;
}