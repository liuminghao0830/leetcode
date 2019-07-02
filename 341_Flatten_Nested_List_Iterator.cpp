#include<bits/stdc++.h>

using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; --i) s.push(nestedList[i]);
    }

    int next() {
        NestedInteger t = s.top(); s.pop();
        if (t.isInteger()) return t.getInteger();
        else {
            for (int i = t.getList().size() - 1; i >= 0; --i) s.push(t.getList()[i]);
        }
        int to = s.top().getInteger(); s.pop();
        return to;
    }

    bool hasNext() {
        while (!s.empty()){
            if (s.top().isInteger()) return true;
            else {
                NestedInteger t = s.top(); s.pop();
                for (int i = t.getList().size() - 1; i >= 0; --i) s.push(t.getList()[i]);
            }
        }
        return false;
    }
};


int main(){
    return 0;
}