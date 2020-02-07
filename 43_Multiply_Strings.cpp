#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    string multiply(string num1, string num2) {
        /* O(n*m) : beat 70% */
        int n = num1.length(), m = num2.length();

        vector<int> res(n + m);
        for (int i = n - 1; i >= 0; --i){
            for (int j = m - 1; j >= 0; --j){
                int d = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = d + res[p2];
                res[p1] += sum / 10;
                res[p2] = sum % 10;
            }
        }
        string r = "";
        for (int n : res) {
            if (!(r.empty() && n == 0)) r += to_string(n);
        }
        return r.empty() ? "0" : r;
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->multiply("123", "456") << "\n";
    return 0;
}