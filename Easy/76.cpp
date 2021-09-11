/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<int> v1;
    vector<int> v2;
    
    void init() {
        v1.clear();
        v2.clear();
    }
    
    void getArray(TreeNode* root, vector<int> &v) {
        if(!root) return;
        
        getArray(root->left, v);
        if(!root->left && !root->right) v.push_back(root->val);
        getArray(root->right, v);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        init();
        
        getArray(root1, v1);
        getArray(root2, v2);
        
        if(v1.size() != v2.size()) return false;
        
        for(int i=0; i<v1.size(); i++)
            if(v1[i] != v2[i])
                    return false;
        
        return true;
    }
};