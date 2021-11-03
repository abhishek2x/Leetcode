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
    int res;
    void do_work(TreeNode* root, unsigned int n) {
        if(!root->left && !root->right) {
            n = n*10 + root->val;
            res += n;
        }
        
        n = n*10 + root->val;
        
        if(root->left) do_work(root->left, n);
        if(root->right) do_work(root->right, n);
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        unsigned int n=0;
        res=0;
        do_work(root, n);
        return res;
    }
};