#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution{
private:
    Node* dfs_copy(Node* node, unordered_map<Node*, Node*>& m){
        if (m.count(node)) return m[node];

        Node* nnode = new Node(node->val);
        m[node] = nnode;
        for (auto neigh : node->neighbors){
            nnode->neighbors.push_back(dfs_copy(neigh, m));
        }
        return nnode;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map<Node*, Node*> m;
        return dfs_copy(node, m);
    }
};


int main(){
    return 0;
}