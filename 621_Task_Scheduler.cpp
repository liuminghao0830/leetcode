#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        /* O(2*n) : 94% */
        vector<int> cnt(26, 0);
        for (auto task : tasks) cnt[task - 'A']++;
        sort(cnt.begin(), cnt.end());
        
        int i = 25, mx = cnt[25];
        while (i >= 0 && cnt[i] == mx) i--;
        return max((int)tasks.size(), (mx - 1) * (n + 1) + 25 - i);
    }
};

int main(){
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    Solution* solution = new Solution();
    cout << solution->leastInterval(tasks, 2) << endl;
    return 0;
}