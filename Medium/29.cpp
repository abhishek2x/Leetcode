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
    map<int, int> mp; //<level, sum> 
    
    void do_work(TreeNode* root, int level) {
        if(!root) return;
        mp[level] += root->val;
        do_work(root->left, level+1);
        do_work(root->right, level+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        mp.clear();
        do_work(root, 0);
        return mp.rbegin()->second;
    }
};