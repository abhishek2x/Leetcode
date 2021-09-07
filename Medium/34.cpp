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
    TreeNode* dowork(vector<int>&a, int l, int h) {
        if(l > h) return nullptr;
        
        int idx = max_element(a.begin() + l, a.begin() + h + 1) - a.begin();
        
        TreeNode* root = new TreeNode(a[idx]);
        
        root->left = dowork(a, l, idx-1);
        root->right = dowork(a, idx+1, h);
        
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& a) {
        return dowork(a, 0, a.size()-1);
    }
};