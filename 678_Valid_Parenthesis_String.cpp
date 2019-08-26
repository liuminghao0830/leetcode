#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool checkParenthesis(string s, int i, int cnt){
        if (cnt < 0) return false;
        for (int j = i; j < s.length(); ++j){
            if (s[j] == '(') cnt++;
            else if (s[j] == ')'){
                if (cnt <= 0) return false;
                cnt--;
            }
            else {
                if (checkParenthesis(s, j + 1, cnt)) return true;
                if (checkParenthesis(s, j + 1, cnt + 1)) return true;
                if (checkParenthesis(s, j + 1, cnt - 1)) return true;
            }
        }
        return cnt == 0;
    }
public:
    bool checkValidString2(string s) {
        /* O(3^num(*)) : TLE */
        if (s.empty()) return true;
        return checkParenthesis(s, 0, 0);
    }

    bool checkValidString(string s){
        /* O(n) : 100% */
        stack<int> left, star;
        for (int i = 0; i < s.length(); ++i){
            if (s[i] == '(') left.push(i);
            else if (s[i] == '*') star.push(i);
            else {
                if (left.empty() && star.empty()) return false;
                else if (!left.empty()) left.pop();
                else star.pop();
            }
        }
        while (!left.empty() && !star.empty()){
            if (left.top() > star.top()) return false;
            left.pop(); star.pop();
        }
        return left.empty();
    }
};

int main(){
    Solution* solution = new Solution();
    cout << solution->checkValidString("((()))()(())(*()()())**(())()()()()((*()*))((*()*)"
) << endl;
    return 0;
}