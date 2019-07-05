#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};


class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* node = head;
        
        while (node){
            Node* next = node->next;
            if (node->child){
                Node* c = flatten(node->child);
                node->child = NULL;
                c->prev = node;
                node->next = c;
                while (c->next) c = c->next;
                c->next = next;
                if (next) next->prev = c;
            }
            node = next;
        }
        
        return head;
    }
};


int main(){
    return 0;
}
