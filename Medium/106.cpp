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
    
    int totalNodes=0;
    
    void do_work(TreeNode* root) {
        if(!root) return;
        totalNodes++;
        
        do_work(root->left);
        do_work(root->right);
    }
    
    int countNodes(TreeNode* root) {
        do_work(root);
        return totalNodes;
    }
};