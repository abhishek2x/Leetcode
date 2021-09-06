/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* res;
    TreeNode* t;
    
    void inorder(TreeNode* original, TreeNode* cloned) {
        if(!original) return;
        
        inorder(original->left, cloned->left);
        if(original == t) res = cloned; 
        inorder(original->right, cloned->right);
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original) return NULL;
        t = target;
        
        inorder(original, cloned);
        return res;
    }
};