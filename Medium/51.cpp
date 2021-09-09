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
    vector<TreeNode*> forest;
    
    void helper(TreeNode* &root, vector<int>& to_delete) {
        if(!root) return;
        
        helper(root->left, to_delete);
        helper(root->right, to_delete);
        
        if(find(to_delete.begin(), to_delete.end(), root->val) != to_delete.end()) {
            if(root->left) forest.push_back(root->left);
            if(root->right) forest.push_back(root->right);
            root = NULL;
            delete root;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        forest.clear();

        if(find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end())
            forest.push_back(root);
        
        helper(root, to_delete);
        return forest;
    }
};