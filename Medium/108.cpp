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

// 2 pointer method
class Solution {
public:
    int total = 0;
    
    void paths(TreeNode* root, int currSum, int targetSum) {
        if(!root) return;
        if(currSum + root->val == targetSum) total++;
        
        paths(root->left, currSum + root->val, targetSum);
        paths(root->right, currSum + root->val, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;    
        
        paths(root, 0, targetSum);
        
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return total;
    }
};