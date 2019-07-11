#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<int, bool> m;
    
    bool dfs(int max_n, int tot, int use){
        if (m.count(use)) return m[use];
        
        for (int i = 0; i < max_n; ++i){
            int cur = (1 << i);
            if ((cur & use) != 0) continue;
            if (tot <= i + 1 || !dfs(max_n, tot - (i + 1), cur | use)) {
                return m[use] = true;
            }
        }
        
        return m[use] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
        if (sum < desiredTotal) return false;
        if (desiredTotal <= maxChoosableInteger) return true;
        
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->canIWin(10, 11) << endl;
    return 0;
}