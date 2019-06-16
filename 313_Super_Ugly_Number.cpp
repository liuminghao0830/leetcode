#include<bits/stdc++.h>

using namespace std;


/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime 
factors are in the given prime list primes of size k.

Input: n = 12, primes = [2,7,13,19]
Output: 32 
Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the 
    first 12 super ugly numbers given primes = [2,7,13,19] of size 4.
*/


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (!n || primes.empty()) return 0;

        unordered_map<int, int> m; int ps = primes.size();
        vector<int> res(1, 1);

        while (res.size() < n){
            int min_prime = INT_MAX;
            for (int p : primes) {
                min_prime = min(min_prime, res[m[p]] * p);
            }
            
            for (int p : primes) {
                if (min_prime == res[m[p]] * p) m[p]++;
            }

            res.push_back(min_prime);
        }

        return res.back();
    }

};

Solution solution;

int main(){
    vector<int> primes{2, 7, 13, 19};
    int n = 12;

    auto res = solution.nthSuperUglyNumber(n, primes);
    
    cout << res << "\n";
    
    return 0;
}
