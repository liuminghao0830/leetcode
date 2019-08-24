#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        /* O(71*n) : 5% */
        int n = T.size(); vector<int> res(n, 0);
        unordered_map<int, int> m;
        for (int i = n - 1; i >= 0; --i){
            m[T[i]] = i;
            for (int t = T[i] + 1; t < 101; ++t){
                if (m.count(t) && (!res[i] || m[t] < res[i] + i)) {
                    res[i] = m[t] - i;
                }
            }
        }
        return res;
    }

    vector<int> dailyTemperatures_stack(vector<int>& T) {
        /* O(n) : 78% */
        int n = T.size(); vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < n; ++i){
            while (!st.empty() && T[i] > T[st.top()]){
                auto t = st.top(); st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> T{73, 74, 75, 71, 69, 72, 76, 73};
    auto res = solution->dailyTemperatures_stack(T);
    for (auto t : res) cout << t << " ";
    cout << "\n";
    return 0;
}