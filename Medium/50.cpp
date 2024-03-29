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
    
    pair<TreeNode*, int> helper(TreeNode* root) {
        if(!root) return {root, 0};
        
        auto l = helper(root->left);
        auto r = helper(root->right);
        
        if(l.second == r.second) return {root, l.second+1};
        if(l.second > r.second) return {l.first, l.second+1};
        return {r.first, r.second+1};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
    }
};
