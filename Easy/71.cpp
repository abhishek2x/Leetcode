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
    int max_depth;
    
    void helper(TreeNode* root, int curr_depth){
        if(!root) return;
        
        if(curr_depth > max_depth) max_depth = curr_depth;
        
        helper(root->left, curr_depth+1);
        helper(root->right, curr_depth+1);
    }
    
    int maxDepth(TreeNode* root) {
        max_depth=0;
        helper(root, 1);
        return max_depth;
    }   
};