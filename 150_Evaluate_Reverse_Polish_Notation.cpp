#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
public:
    int evalRPN(vector<string>& tokens) {
        /* O(tokens.size()) : 90% */
        stack<int> s;
        for (string str : tokens){
            if (str == "+" || str == "-" || str == "*" || str == "/"){
                int t2 = s.top(); s.pop();
                int t1 = s.top(); s.pop();
                if (str == "+") s.push(t1 + t2);
                else if (str == "-") s.push(t1 - t2);
                else if (str == "*") s.push(t1 * t2);
                else s.push(t1 / t2);
            }
            else {
                s.push(stoi(str));
            }
        }
        return s.top();
    }
};

int main(){
    vector<string> tokens{"4", "13", "5", "/", "+"};
    Solution* solution = new Solution();
    cout << solution->evalRPN(tokens) << "\n";
    return 0;
}