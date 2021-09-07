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
    vector<int> inorder;
    int idx;
    
    void init() {
        inorder.clear();
        idx=0;
    }
    
    void do_inorder(TreeNode* root){ 
        if(!root) return ;
        do_inorder(root->left);
        inorder.push_back(root->val);
        do_inorder(root->right);
    }
    
    TreeNode* flattened(int len) {
        if(idx == len) return NULL;
        
        TreeNode* root = new TreeNode(inorder[idx++]);
        root->left = NULL;
        root->right = flattened(len);
        return root;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        init();
        do_inorder(root);
        return flattened(inorder.size());
    }
};