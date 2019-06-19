#include<bits/stdc++.h>

using namespace std;

/*
Given an array of citations sorted in ascending order (each 
citation is a non-negative integer) of a researcher, write a 
function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A 
scientist has index h if h of his/her N papers have at least 
h citations each, and the other N − h papers have no more 
than h citations each."
*/

class Solution{
public:
    int hIndex(vector<int>& citations){
        if (citations.empty()) return 0;
        int n = citations.size();
        int left = 0; int right = n - 1;

        while (left <= right){
            int mid = (left + right) / 2;
            if (citations[mid] < n - mid) left = mid + 1;
            else if (citations[mid] > n - mid) right = mid - 1;
            else return n - mid;
        }

        return n - left;
    }   
};  Solution solution;


int main(){
    vector<int> citations{0, 1, 3, 5, 6};
    int res = solution.hIndex(citations);

    cout << res << endl;

    return 0;
}
