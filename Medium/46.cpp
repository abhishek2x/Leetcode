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
    
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    
    void deleteLeaf(TreeNode* root) {
        if(!root) {
            return;
        }
        
        deleteLeaf(root->left);
        
        if(root->left) if(isLeaf(root->left) && root->left->val == 0) root->left = NULL; 
        if(root->right) if(isLeaf(root->right) && root->right->val == 0) root->right = NULL; 
        
        deleteLeaf(root->right);
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        deleteLeaf(root);        
        return root;
    }
};