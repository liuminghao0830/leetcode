#include<bits/stdc++.h>

using namespace std;

class MyCalendar {
private:
    vector<vector<int>> v;
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        if (v.empty()) {
            v.push_back({start, end});
            return true;
        }
        if (end <= v[0][0]) {
            v.insert(v.begin(), {start, end});
            return true;
        }
        if (start >= v.back()[1]) {
            v.insert(v.end(), {start, end});
            return true;
        }
        for (int i = 0; i < v.size(); ++i){
            if (start > v[i][0] && start < v[i][1]) return false;
            else if (end > v[i][0] && end < v[i][1]) return false;
            if (i > 0 && start >= v[i - 1][1] && end <= v[i][0]){
                v.insert(v.begin() + i, {start, end});
                return true;
            }
        }
        return false;
    }
    bool book_improve(int start, int end) {
        for (int i = 0; i < v.size(); ++i){
            if (v[i][0] <= start && v[i][1] > start) return false;
            if (v[i][0] >= start && v[i][0] < end) return false;
        }
        v.push_back({start, end});
        return true;
    }
};

int main(){
    MyCalendar* calendar = new MyCalendar();
    cout << calendar->book(10, 20) << endl;
    cout << calendar->book(15, 25) << endl;
    cout << calendar->book(20, 30) << endl;
    return 0;
}