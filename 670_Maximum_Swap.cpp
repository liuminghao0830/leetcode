#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    int maximumSwap(int num){
        /* O(n^2) : 54% */
        string sn = to_string(num);
        string _max = sn;
        for (int i = 0; i < sn.length() - 1; ++i){
            for (int j = i + 1; j < sn.length(); ++j){
                swap(sn[i], sn[j]);
                _max = max(_max, sn);
                swap(sn[i], sn[j]);
            }
        }
        return stoi(_max);
    }
    int maximumSwap2(int num){
        /* one pass O(n) : 100% */
        string sn = to_string(num);
        int len = sn.length();
        int c1 = -1, c2 = -1; int mn = len - 1;
        for (int i = len - 2; i >= 0; --i){
            if (sn[i] < sn[mn]){
                c1 = i; c2 = mn;
            }
            else if (sn[i] > sn[mn]) mn = i;
        }
        if (c1 != -1 && c2 != -1) swap(sn[c1], sn[c2]);
        return stoi(sn);
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->maximumSwap(2736) << endl;
    return 0;
}