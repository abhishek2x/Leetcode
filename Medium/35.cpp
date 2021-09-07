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
    unordered_map<int, vector<TreeNode*>> mp;
    
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        
        if(mp[n].size() != 0) return mp[n];
        if(n == 1) {
            ans.push_back(new TreeNode(0));
        }
        
        for(int i=1; i<n; i+=2) {
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n-i-1);
            
            for(auto v1: left) {
                for(auto v2: right) {
                    TreeNode* root = new TreeNode(0);
                    root->left = v1;
                    root->right = v2;
                    ans.push_back(root);
                }
            }
        }
        
        return mp[n] = ans;
    }
};