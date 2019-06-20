#include<bits/stdc++.h>

using namespace std;

/*
Given a string of numbers and operators, return all possible 
results from computing all the different possible ways to 
group numbers and operators. The valid operators are +, 
- and *.
*/


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.length(); ++i){
            if (input[i] == '+' || input[i] == '-' || input[i] == '*'){
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for (int j = 0; j < left.size(); ++j){
                    for (int k = 0; k < right.size(); ++k){
                        if (input[i] == '+') res.push_back(left[j]+right[k]);
                        else if (input[i] == '-') res.push_back(left[j]-right[k]);
                        else res.push_back(left[j]*right[k]);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
}; Solution solution;


int main(){
    string input = "2*3-4*5";
    vector<int> res = solution.diffWaysToCompute(input);

    for (int n : res) cout << n << " ";
    cout << "\n";

    return 0;
}
