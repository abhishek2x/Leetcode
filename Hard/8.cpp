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
    
    int cameras;
    
    int _minCameraCover(TreeNode* root) {
        if(!root) return 1;
        
        int lChild = _minCameraCover(root->left);
        int rChild = _minCameraCover(root->right);
        
        if(lChild == -1 || rChild == -1) {cameras++; return 0;}
        if(lChild == 0 || rChild == 0) return 1;
        
        return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        if(!root) return 0;
        cameras = 0;
        
        if(_minCameraCover(root) == -1) cameras++;
        return cameras;
    }
};