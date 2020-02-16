#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    string getPermutation(int n, int k) {
        /*O(n) : 80% */
        string num = "123456789";
        string res;
        vector<int> fn(n, 1);
        for (int i = 1; i <= n; ++i) fn[i] = fn[i - 1] * i;
        k--;
        //for (int s : fn) cout << s << " ";
        for (int i = n; i > 0; --i){
            int j = k / fn[i - 1];
            k = k % fn[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->getPermutation(3, 3) << "\n";
    return 0;
}