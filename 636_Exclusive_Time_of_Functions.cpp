#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
    vector<string> read_time(string log){
        vector<string> res; int s = 0;
        for (int i = 0; i < log.length(); ++i){
            if (log[i] == ':') {
                res.push_back(log.substr(s, i - s));
                s = i + 1;
            }
        }
        res.push_back(log.substr(s, log.length() - s));
        return res;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0); stack<string> st;
        for (string log : logs){
            auto log_arr = read_time(log);
            if (log_arr[1] == "start") st.push(log);
            else {
                auto start = read_time(st.top()); st.pop();
                int et = stoi(log_arr[2]) - stoi(start[2]) + 1;
                res[stoi(log_arr[0])] += et;
                if (!st.empty()){
                    int last_id = stoi(read_time(st.top())[0]);
                    res[last_id] -= et;
                }

            }
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<string> logs{"0:start:0", "1:start:2", "1:end:5", "0:end:6"};
    auto res = solution->exclusiveTime(2, logs);
    for (auto r : res) cout << r << " ";
    cout << "\n";
    return 0;
}