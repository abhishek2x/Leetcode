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
    int max_depth;
    
    void get_depth(Node* root, int curr_depth) {
        if(!root) return;
        
        for(auto child: root->children) {
            max_depth = max(max_depth, curr_depth+1);
            get_depth(child, curr_depth+1);
        }
    }
    
    int maxDepth(Node* root) {
        if(!root) return 0;
        max_depth=1;
        get_depth(root, 1);
        return max_depth;
    }
};