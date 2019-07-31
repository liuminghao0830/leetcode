#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    void serialize(TreeNode* root, ostringstream& s){
        if (!root) s << "# ";
        else {
            s << root->val << " ";
            serialize(root->left, s);
            serialize(root->right, s);
        }
    }
    TreeNode* deserialize(istringstream& s){
        string val;
        s >> val;
        if (val == "#") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(s);
        root->right = deserialize(s);
        return root;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream s;
        serialize(root, s);
        return s.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream s(data);
        auto root = deserialize(s);
        return root;
    }
};

int main(){
    Codec codec;
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    auto ds = codec.deserialize(codec.serialize(root));
    cout << ds->val << " ";
    cout << ds->left->val << " ";
    cout << ds->right->val << "\n";
    return 0;
}