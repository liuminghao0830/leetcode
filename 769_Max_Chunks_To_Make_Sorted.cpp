#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        /*O(n) : 50% */
        int cnt = 0, mx = INT_MIN;
        for (int i = 0; i < arr.size(); ++i){
            mx = max(mx, arr[i]);
            if (i == mx) { cnt++; mx = INT_MIN; }
        }
        return cnt;
    }
};

int main(){
    vector<int> arr{4, 3, 2, 1, 0};
    Solution* solution = new Solution();
    cout << solution->maxChunksToSorted(arr) << endl;
    return 0;
}