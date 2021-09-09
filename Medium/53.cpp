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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(!root) return v;
        
        queue<Node*> q;
        q.push(root);
        v.push_back({root->val});
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            
            while(size--) {
                Node* node = q.front();
                q.pop();
                for(auto child: node->children) {
                    q.push(child);
                    temp.push_back(child->val);
                }
            }
            if(temp.size())
                v.push_back(temp);
        }
        return v;
    }
};