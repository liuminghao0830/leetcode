#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int shortestDistance(vector<string>& words, string word1, string word2){
		int res = words.size(), p1 = -1, p2 = -1;
		for (int i = 0; i < words.size(); ++i){
			if (words[i] == word1) p1 = i;
			else if (words[i] == word2) p2 = i;
			if (p1 >= 0 && p2 >= 0) res = min(res, abs(p1 - p2));
		}
		return res;
	}
};

int main(){
	Solution* solution = new Solution();
	vector<string> words = {"practice", "makes", "perfect", "coding", "makes"};
	cout << solution->shortestDistance(words, "coding", "practice") << "\n";
	return 0;
}