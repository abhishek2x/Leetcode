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
    int sum;
    int ol;
    
    void do_work(TreeNode* root, int cl) {
        if(!root) return;
        
        if(cl == ol) sum += root->val;
        if(cl > ol) {
            ol = cl;
            sum=root->val;
        }
        
        do_work(root->left, cl+1);
        do_work(root->right, cl+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        sum=0;
        ol=0;
        do_work(root, 0);
        return sum;
    }
};