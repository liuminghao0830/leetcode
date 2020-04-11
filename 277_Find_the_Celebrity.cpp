#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findCelebrity_brute_force(int n) {
        vector<int> in(n, 0), out(n, 0);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (i == j) continue;
                if (knows(i, j)) { in[j]++; out[i]++; }
            }
        }
        for (int i = 0; i < n; ++i){
            if (in[i] == n - 1 && out[i] == 0) return i;
        }
        return -1;
    }
    int findCelebrity(int n) {
        for (int i = 0; i < n; ++i){
            int j;
            for (j = 0; j < n; ++j){
                if (i != j && (knows(i, j) || !knows(j, i))) break;
            }
            if (j == n) return i;
        }
        return -1;
    }
};