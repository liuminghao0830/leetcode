#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<string> rotate(string key){
        vector<string> res;
        for (int i = 0; i < 4; ++i){
            string p = key;
            p[i] = (p[i] + 1 - '0') % 10 + '0';
            res.push_back(p);
            string m = key;
            m[i] = (m[i] - 1 - '0' + 10) % 10 + '0';
            res.push_back(m);
        }
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        /*BFS O(9^4) : 27% */
        unordered_set<string> dde;
        for (auto d : deadends) dde.insert(d);
        if (dde.count(target) || dde.count("0000")) return -1;
        int cnt = 0; 
        unordered_set<string> vis; vis.insert("0000");
        queue<string> q; q.push("0000");
        while (!q.empty()){
            int n = q.size();
            for (int i = 0; i < n; ++i){
                string t = q.front(); q.pop();
                vector<string> next = rotate(t);
                for (auto n : next){
                    if (dde.count(n)) continue;
                    if (n == target) return ++cnt;
                    if (!vis.count(n)){
                        q.push(n);
                        vis.insert(n);
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
    cout << solution->openLock(deadends, "0202") << endl;
}