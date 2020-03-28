#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int res = INT_MAX;
        vector<vector<int>> Wordmap(2, vector<int>());
        for (int i = 0; i < words.size(); ++i){
            if (words[i] == word1) Wordmap[0].push_back(i);
            if (words[i] == word2) Wordmap[1].push_back(i);
        }
        for (int i = 0; i < Wordmap[0].size(); ++i){
            for (int j = 0; j < Wordmap[1].size(); ++j){
                if (Wordmap[0][i] != Wordmap[1][j]) {
                    res = min(res, abs(Wordmap[0][i] - Wordmap[1][j]));
                }
            }
        }
        return res;
    }
};

int main(){
    return 0;
}
