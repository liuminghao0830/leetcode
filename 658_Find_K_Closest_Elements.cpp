#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x){
        /*O(nlogn) : 16% */
        map<int, vector<int>> m;
        for (int num : arr) m[abs(x - num)].push_back(num);

        vector<int> res;
        for (auto t : m){
            for (int n : t.second){
                res.push_back(n); k--;
                if (k <= 0) break;
            }
            if (k <= 0) break;
        }
        sort(res.begin(), res.end());
        return res;
    }
    vector<int> findClosestElements_BS(vector<int>& arr, int k, int x){
        /*O(k*logn) : 70% */
        vector<int> res; int n = arr.size();
        int left = 0, right = arr.size() - 1;
        while (left < right){
            int mid = (left + right) / 2;
            if (arr[mid] <= x) left = mid + 1;
            else right = mid;
        }
        if (left == right) left--;
        while (k > 0){
            if (left < 0) res.push_back(arr[right++]);
            else if (right >= n) res.push_back(arr[left--]);
            else if (x - arr[left] <= arr[right] - x) {
                res.push_back(arr[left--]);
            }
            else res.push_back(arr[right++]);
            k--;
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution* solution = new Solution();
    vector<int> arr{1, 2, 3, 4, 5};
    auto res = solution->findClosestElements_BS(arr, 4, -1);
    for (int r : res) cout << r << " ";
    cout << "\n";
    return 0;
}