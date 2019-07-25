#include<bits/stdc++.h>

using namespace std;

class Solution{
private:
    int cnt = 0;
public:
    void recursion(int N, int p, vector<bool> &visit){
        if (p > N) { cnt++; return; };
        
        for (int i = 1; i <= N; ++i){
            if (!visit[i] && (i % p == 0 || p % i == 0)){
                visit[i] = true;
                recursion(N, p + 1, visit);
                visit[i] = false;
            }
        }
    }

    int countArrangement(int N) {
        vector<bool> visit(N + 1, false);
        recursion(N, 1, visit);
        return cnt;
    }
};

int main(){
    int N = 2;
    Solution* solution = new Solution();
    cout << solution->countArrangement(N) << endl;
    return 0;
}