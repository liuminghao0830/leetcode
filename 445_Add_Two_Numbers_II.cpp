#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* dfs(ListNode* l, ListNode* l1, ListNode* l2, int& carry){
        if (!l1 && !l2) return NULL;
        
        l = new ListNode(0);
        l->next = dfs(l->next, l1->next, l2->next, carry);
        
        int num = l1->val + l2->val + carry;
        
        l->val = num % 10;
        carry = num > 9 ? num / 10 : 0;
        
        return l;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = 0; int len2 = 0;
        ListNode* n1 = l1; ListNode* n2 = l2;
        while (n1){n1 = n1->next; len1++;}
        while (n2){n2 = n2->next; len2++;}
        
        ListNode* a = new ListNode(0); ListNode* temp = a;
        for (int i = 0; i < abs(len2-len1); ++i){
            a->next = new ListNode(0);
            a = a->next;
        }
        
        a->next = len2 > len1 ? l1 : l2;
        if (len2 > len1) l1 = temp->next;
        else if (len1 > len2) l2 = temp->next;
        
        ListNode* dummy = new ListNode(0);
        int carry = 0;
        
        dummy->next = dfs(dummy->next, l1, l2, carry);
        dummy->val = carry;
        
        return carry == 0 ? dummy->next : dummy;
    }
}; Solution solution;


int main(){
    ListNode* l1 = new ListNode(7); ListNode* h1 = l1; 
    l1->next = new ListNode(2); l1 = l1->next;
    l1->next = new ListNode(4); l1 = l1->next;
    l1->next = new ListNode(3);
    ListNode* l2 = new ListNode(5); ListNode* h2 = l2; 
    l2->next = new ListNode(6); l2 = l2->next;
    l2->next = new ListNode(4);

    auto sum_node = solution.addTwoNumbers(h1, h2);

    while (sum_node) {
        cout << sum_node->val << " "; 
        sum_node = sum_node->next;
    }
    cout << "\n";

    return 0;
}