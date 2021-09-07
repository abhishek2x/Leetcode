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
    int minTillNow;
    
    void init() {
        ans=0;
        minTillNow=-1;
    }
    
    void count_utility(TreeNode* root) {
        if(!root) return;
        minTillNow = max(minTillNow, root->val);
        
        if(root->val >= minTillNow) ans++;
        count_utility(root->left);
        count_utility(root->right);
    }
    
    int goodNodes(TreeNode* root) {
        void();
        count_utility(root);
        return ans;
    }
};