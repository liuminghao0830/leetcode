#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        /* O(n) : 90% */
        unordered_map<int, int> m; int cnt = 0;
        for (int c : answers) m[c]++;
        for (auto a : m){
            while (m[a.first] > a.first){
                cnt += a.first + 1;
                m[a.first] -= a.first + 1;
            } 
            if (m[a.first] > 0) cnt += a.first + 1; 
        }
        
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> answers{1, 1, 0, 0, 0};
    cout << solution->numRabbits(answers) << endl;
    return 0;
}