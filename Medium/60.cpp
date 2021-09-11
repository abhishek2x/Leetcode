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
    
    int maxHeight;
    int value;
    
    void init() {
        maxHeight=-1;
        value=0;
    }
    
    void recur(TreeNode* root , int c_level) {
        if(!root) return;
        
        if(c_level > maxHeight) {
            maxHeight = c_level;
            value = root->val;
        }
        
        recur(root->left, c_level+1);
        recur(root->right, c_level+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        init();
        recur(root, 0);
        return value;
    }
};