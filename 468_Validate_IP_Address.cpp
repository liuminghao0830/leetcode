#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string validIPAddress(string IP) {
        int i = 0; char mark;
        while ((IP[i] != '.' && IP[i] != ':') && (i < IP.length())) i++;
        if (i == IP.length()) return "Neither";
        mark = IP[i]; IP += mark;
        
        i = 0; string num = ""; int cnt = 0;
        while (i < IP.length()){
            if (IP[i] != mark) {
                if (IP[i] < '0') return "Neither";
                if (mark == '.' && IP[i] > '9') return "Neither";
                if (mark == ':'){
                    if (!(IP[i] >= '0' && IP[i] <= '9') && !(IP[i] >= 'a' && IP[i] <= 'f') && !(IP[i] >= 'A' && IP[i] <= 'F')) return "Neither";
                }
                num += IP[i++];
                continue;
            }
            if (num == "") return "Neither";
            if (mark == '.'){
                if (num.length() > 3) return "Neither";
                if (num[0] == '0' && num.length() > 1) return "Neither";
                if (stoi(num) < 0 || stoi(num) > 255) return "Neither";
            }
            else {
                if (num.length() > 4) return "Neither";
            }
            num = ""; cnt++; i++;
        }
        if (mark == '.' && cnt != 4) return "Neither";
        else if (mark == ':' && cnt > 8) return "Neither";
        
        return mark == '.' ? "IPv4" : "IPv6";
    }
};

int main(){
    Solution* solution = new Solution();
    string IP = "172.16.254.1";
    cout << solution->validIPAddress(IP) << endl;

    return 0;
}