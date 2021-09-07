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
    
    void dowork(TreeNode* root) {
        if(!root) return;
        
        dowork(root->right);
        sum += root->val; root->val = sum;
        dowork(root->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        sum=0;
        dowork(root);
        return root;
    }
};