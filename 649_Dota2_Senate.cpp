#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    string predictPartyVictory(string senate) {
        /* O(n) : 89% */
        queue<int> radiant, dire; int n = senate.size();
        for (int i = 0; i < senate.length(); ++i) {
            if (senate[i] == 'R') radiant.push(i);
            else dire.push(i);
        }
        while (!radiant.empty() && !dire.empty()){
            int r = radiant.front(); radiant.pop();
            int d = dire.front(); dire.pop();
            if (r < d) {
                radiant.push(r + n);
            }
            else dire.push(d + n);
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->predictPartyVictory("RD") << endl;
    return 0;
}