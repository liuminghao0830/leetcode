#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;

        for (auto p : people){
            res.insert(res.begin() + p[1], p);
        }

        return res;
    }
};

int main(){
    vector<vector<int>> people;
    people.push_back({7, 0});
    people.push_back({4, 4});
    people.push_back({7, 1});
    people.push_back({5, 0});
    people.push_back({6, 1});
    people.push_back({5, 2});
    
    Solution* solution = new Solution();
    auto res = solution->reconstructQueue(people);
    
    for (auto r : res){
        for (auto c : r) cout << c << " ";
        cout << "\n";
    }
    return 0;
}