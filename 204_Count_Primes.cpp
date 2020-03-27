#include<iostream>

using namespace std;

class Solution{
public:
    int CountPrimes(int n){
        vector<bool> primes(n, true);
        int cnt = 0;
        for (long i = 2; i < n; ++i){
            if (!primes[i]) continue;
            cnt++;
            for (long j = i; i * j < n; ++j){
                primes[i * j] = false;
            }
        }
        return cnt;
    }
};

int main(){
    Solution* solution = new Solution();

    return 0;
}