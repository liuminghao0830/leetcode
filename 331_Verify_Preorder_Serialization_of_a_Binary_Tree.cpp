#include<bits/stdc++.h>

using namespace std;

class Solution{
public:
    bool isValidSerialization(string preorder){
        stringstream str(preorder);
        vector<string> v; int cnt = 0; string t;

        while (getline(str, t, ',')) v.push_back(t);

        for (int i = 0; i < v.size() - 1; ++i){
            if (v[i] == "#"){
                if (cnt == 0) return false;
                cnt--;
            }
            else cnt++;
        }

        return (v.back() == "#") && (cnt == 0);
    }   
}; Solution solution;

int main(){
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << solution.isValidSerialization(preorder) << endl;

    return 0;
}
