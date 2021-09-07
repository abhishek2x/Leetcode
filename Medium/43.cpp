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
    int ans;
    
    void count_utility(TreeNode* root, int maxTillNow) {
        if(!root) return;
        
        if(root->val >= maxTillNow) ans++;
        maxTillNow = max(maxTillNow, root->val);
                         
        count_utility(root->left, maxTillNow);
        count_utility(root->right, maxTillNow);
    }
    
    int goodNodes(TreeNode* root) {
        ans=0;
        count_utility(root, INT_MIN);
        return ans;
    }
};