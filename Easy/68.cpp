/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    
    void init() {
        ans.clear();
    }
    
    void dowork(Node* root) {
        if(!root) return;
        ans.push_back(root->val);
        
        for(Node* child: root->children)
            dowork(child);
    }
    
    vector<int> preorder(Node* root) {
        init();
        dowork(root);
        return ans;
    }
};