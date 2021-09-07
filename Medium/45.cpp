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
    
    int sum;
    
    void createMasksOpt(TreeNode* root, int mask) {
        if(!root) return;
        
        mask = (mask << 1) | root->val;
        
        if(!root->left && !root->right)
            sum += mask;
                
        createMasksOpt(root->left, mask);
        createMasksOpt(root->right, mask);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        sum=0;
        createMasksOpt(root, 0);
        return sum;
    }
};