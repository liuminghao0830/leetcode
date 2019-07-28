#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int rangeBitwiseAnd(int m, int n){
        int i = 0;
        while (m != n){
            m >>= 1;
            n >>= 1;
            i++;
        }

        return m << i;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->rangeBitwiseAnd(5, 7) << endl;
    return 0;
}