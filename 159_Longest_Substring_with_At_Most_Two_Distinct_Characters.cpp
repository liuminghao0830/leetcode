#include<iostream>
#include<unordered_map>

using namespace std;

class Solution{
public:
	int lengthOfLongestSubstringTwoDistinct(string s){
		// O(n) : 20ms
		unordered_map<char, int> m; 
        int left = 0; int max_len = 0;
        for (int i = 0; i < s.length(); ++i){
            m[s[i]]++;
            while (m.size() > 2){
                m[s[left]]--;
                if (m[s[left]] == 0) m.erase(s[left]);
                left++;
            }
            max_len = max(max_len, i - left + 1);
        }
        return max_len;
	}
};

int main(){
	Solution* solution = new Solution();
	cout << solution->lengthOfLongestSubstringTwoDistinct("eceba") << "\n";
	return 0;
}