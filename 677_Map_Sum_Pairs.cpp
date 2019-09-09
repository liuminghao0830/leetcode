#include<bits/stdc++.h>

using namespace std;

class MapSum {
private:
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int s = 0;
        for (auto t : m){
            int n = prefix.length();
            if (n <= t.first.length() && t.first.substr(0, n) == prefix) s += m[t.first];
        }
        return s;
    }
};

int main(){
    MapSum* ms = new MapSum();
    ms->insert("a", 3);
    cout << ms->sum("ap") << endl;
    ms->insert("b", 2);
    cout << ms->sum("a") << endl;
    return 0;
}