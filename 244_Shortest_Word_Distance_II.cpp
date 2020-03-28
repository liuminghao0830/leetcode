#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<climits>

using namespace std;

class WordDistance{
private:
    unordered_map<string, vector<int>> m;
public:
    WordDistance(vector<string>& words){
        for (int i = 0; i < words.size(); ++i){
            m[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2){
        // time comlexity O(m + n) : beats 37%
        int res = INT_MAX, i = 0, j = 0;
        auto m1 = m[word1], m2 = m[word2];
        while (i < m1.size() && j < m2.size()){
            res = min(res, abs(m1[i] - m2[j]));
            if (m1[i] < m2[j]) i++;
            else j++;
        }
        return res;
    }
};

int main(){
    return 0;
}