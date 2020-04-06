#include<iostream>
#include<vector>

using namespace std;


class Solution{
private:
    void dfs_search(int n, int s, vector<int>& out, 
                        vector<vector<int>>& res){
        if (n == 1) { res.push_back(out); return; }
        
        for (int i = s; i <= n; ++i) {
            if (n % i != 0) continue;
            out.push_back(i);
            dfs_search(n / i, i, out, res);
            out.pop_back();
        }
    }
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res; vector<int> out;
        for (int i = 2; i < n; ++i) {
            if (n % i != 0) continue;
            out.push_back(i);
            dfs_search(n / i, i, out, res);
            out.pop_back();
        }
        return res;
    }
    
    void print_vec2d(vector<vector<int>>& res);
};

void Solution::print_vec2d(vector<vector<int>>& res){
    for (auto row : res) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }
}


int main(){
    Solution* solution = new Solution();
    auto res1 = solution->getFactors(1); 
    solution->print_vec2d(res1);
    
    auto res2 = solution->getFactors(37); 
    solution->print_vec2d(res2);

    auto res3 = solution->getFactors(12); 
    solution->print_vec2d(res3);

    return 0;
}