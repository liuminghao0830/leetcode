#include<bits/stdc++.h>

using namespace std;

/*
Your task is to calculate a^b mod 1337 where a is a positive 
integer and b is an extremely large positive integer given 
in the form of an array.

Eg:
Input: a = 2, b = [1,0]
Output: 1024
*/


class Solution{
public:
    int power(int x, int n){
        if (n == 0) return 1;
        if (n == 1) return x % 1337;

        return power(x%1337, n/2) * power(x%1337, n - n/2) % 1337;
    }
    
    int superPow(int a, vector<int>& b){
        long int res = 1;

        for (auto n : b) {
            res = power(res, 10) * power(a, n) % 1337;
        }

        return res;
    }   
}; Solution solution;


int main(){
    int a = 2147483647; vector<int> b{2, 0, 0};
    auto res = solution.superPow(a, b);

    cout << res << endl;

    return 0;
}
