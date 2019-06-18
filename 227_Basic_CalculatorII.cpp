#include<bits/stdc++.h>

using namespace std;

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, 
+, -, *, / operators and empty spaces . The integer division 
should truncate toward zero.

Eg:
Input: "3+2*2"
Output: 7
*/

class Solution{
public:
    int calculate(string s){
        if (s.empty() || s == " ") return 0;
        stack<int> stk; char op = '+';
        long int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] >='0' && s[i]<= '9') {
                num = num * 10 + s[i] - '0';
            }
            if (s[i] < '0' && s[i] != ' ' || i == s.length()-1){
                if (op == '+') stk.push(num);
                if (op == '-') stk.push(-num);
                if (op == '*' || op == '/'){
                    int temp = (op == '*') ? num*stk.top() : stk.top()/num;
                    stk.pop(); stk.push(temp);
                }
                op = s[i]; num = 0;
            }
        }
        long int res = 0;
        while (!stk.empty()){
            res += stk.top(); stk.pop();
        }

        return res;
    }
}; Solution solution;

int main(){
    string s = " 3+5 / 2 ";
    int res = solution.calculate(s);

    cout << res << endl;

    return 0;
}
