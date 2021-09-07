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
    
    void init() {
        inorder.clear();
    }
    
    void do_inorder(TreeNode* root) {
        if(!root) return;
        
        do_inorder(root->left);
        inorder.push_back(root->val);
        do_inorder(root->right);
    }
    
    TreeNode* makeTree(int start, int end) {
        if(start > end) return NULL;
        
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(inorder[mid]);
        
        root->left = makeTree(start, mid-1);
        root->right = makeTree(mid+1, end);
        
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        void();
        do_inorder(root);
        return makeTree(0, inorder.size()-1);
    }
};