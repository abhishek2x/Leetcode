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
    int d;
    
    int height(TreeNode* root) {
        if(!root) return 0;
        
        int lh = height(root->left);
        int rh = height(root->right);
        
        d = max(1+lh+rh, d);
        return 1+max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return d-1;
    }
};

