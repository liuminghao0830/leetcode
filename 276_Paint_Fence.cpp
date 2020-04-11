#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        else if (n == 1) return k;

        int same = k, diff = k * (k - 1);
        for (int i = 3; i <= n; ++i){
            int temp = diff;
            diff = (same + diff) * (k - 1);
            same = temp;
        }
        return diff + same;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->numWays(3, 2) << "\n";
    return 0;
}