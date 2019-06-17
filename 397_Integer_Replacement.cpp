#include<bits/stdc++.h>

using namespace std;

/*
Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Eg:
Input:
7
Output:
4
Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/

class Solution{
public:
    int integerReplacement(long int n){
        if (n <= 1) return 0;
        
        if (n % 2 == 0) return integerReplacement(n / 2) + 1;
        else return min(integerReplacement(n+1), integerReplacement(n-1)) + 1;

    } 
}; Solution solution;

int main(){
    int n = 2147483647;
    int res = solution.integerReplacement(n);

    cout << res << endl;

    return 0;
}
