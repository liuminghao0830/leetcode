#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
private:
    ListNode* breakList(ListNode* root, int k){
        while (root && k > 1){
            root = root->next;
            k--;
        }
        if (!root) return NULL;
        auto n = root->next;
        root->next = NULL;
        return n;
    }

public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        /* O(n) : 92% */
        int len = 0; auto head = root;
        while (head) { len++; head = head->next; }
        vector<ListNode*> res(k);
        int s = len / k; int r = len % k; int c;
        for (int i = 0; i < k; ++i){
            if (!root) continue;
            c = i < r ? s + 1 : s;
            res[i] = root;
            root = breakList(root, c);
        }
        return res;
    }
};

int main(){
    ListNode* root = new ListNode(1);
    auto head = root;
    for (int i = 2; i < 11; ++i){
        head->next = new ListNode(i);
        head = head->next;
    }
    
    Solution* solution = new Solution();
    auto res = solution->splitListToParts(root, 3);
    for (auto v : res) {
        while (v) {cout << v->val << " "; v = v->next; }
        cout << "\n";
    }
    return 0;
}