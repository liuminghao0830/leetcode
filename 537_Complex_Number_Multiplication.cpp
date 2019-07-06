#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int find_len(int s, string a, char t){
        int i = s;
        while (a[i] != t) i++;
        return i - s;
    }
    string complexNumberMultiply(string a, string b) {
        int real_len1 = find_len(0, a, '+');
        int real_len2 = find_len(0, b, '+');
        int r1 = stoi(a.substr(0, real_len1));
        int r2 = stoi(b.substr(0, real_len2));
        
        int imag_len1 = find_len(real_len1 + 1, a, 'i');
        int imag_len2 = find_len(real_len2 + 1, b, 'i');
        
        int i1 = stoi(a.substr(real_len1 + 1, imag_len1));
        int i2 = stoi(b.substr(real_len2 + 1, imag_len2));
        
        string real = to_string(r1 * r2 - i1 * i2);
        string image = to_string(r1 * i2 + r2 * i1);
        
        return real + '+' + image + 'i';
    }
};

int main(){
    Solution* solution = new Solution();
    string a = "-11+-30i"; string b = "55+-69i";
    auto res = solution->complexNumberMultiply(a, b);

    cout << res << endl;

    return 0;
}