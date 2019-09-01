#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        /*O(n) : 97% */
        stack<int> st; vector<int> res;
        for (auto a : asteroids){
            if (st.empty() || a * st.top() > 0 || (a > 0 && st.top() < 0)) {st.push(a); continue; }
            else if (st.top() == abs(a)) {st.pop(); continue;}
            while (!st.empty() && a * st.top() < 0 && st.top() < abs(a)){
                st.pop();
            }
            if (st.empty() || a * st.top() > 0) st.push(a);
            else if (st.top() == abs(a)) st.pop();
        }
        while (!st.empty()){
            res.push_back(st.top()); st.pop();
        }
        return vector<int>(res.rbegin(), res.rend());
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> asteroids{5, 10, -5};
    auto res = solution->asteroidCollision(asteroids);
    for (auto r : res) cout << r << " ";
    cout << "\n";
    return 0;
}