#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    string replaceWords(vector<string>& dict, string sentence) {
        sort(dict.begin(), dict.end(), [](string a, string b){
            return a.length() < b.length();
        });

        istringstream str(sentence); 
        string word; string res = "";
        while (str >> word){
            int len = res.length();
            for (int i = 0; i < dict.size(); ++i){
                string d = dict[i];
                for (int j = 0; j < d.length(); ++j){
                    if (d[j] != word[j]) break;
                    else if (j == d.length() - 1) { res += d + ' '; } 
                }
                if (len != res.length()) break;
            }
            if (len == res.length()) res += word + ' ';
        }
        res.erase(res.length() - 1);
        return res;
    }
};

int main(){
    vector<string> dict{"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    Solution* solution = new Solution();
    cout << solution->replaceWords(dict, sentence) << endl;
    return 0;
}