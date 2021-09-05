#include <bits/stdc++.h>
using namespace std;

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
    
    void util(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) return;
        
        if(root1 != root2) {
            root1->val += root2->val;
            
            if(!root1->left && root2->left) root1->left = root2->left;
            if(!root1->right && root2->right) root1->right = root2->right;
        }

        util(root1->left, root2->left);
        util(root1->right, root2->right);
    }
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && root2) return root2;
        if(root1 && !root2) return root1;
        
        util(root1, root2);
        
        return root1;
    }
};