#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    string fractionAddition(string expression) {
        stringstream s(expression);
        int a = 0, b = 1;
        int num, dem; char slash;
        
        while (s >> num >> slash >> dem){
            a = a * dem + num * b;
            b *= dem;
            int g = abs(gcd(a, b));
            a /= g; b /= g;
        }
        
        return to_string(a) + '/' + to_string(b);
    }
};

int main(){
    Solution* solution = new Solution();
    string express = "1/3-1/2";
    cout << solution->fractionAddition(express) << endl;
    return 0;
}