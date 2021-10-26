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

// optimised - O(n)

class Solution {
public:
    int total = 0;
    unordered_map<int, int> mp;
    
    void util(TreeNode* root, int c_sum, int target) {
        if(!root) return;
        
        c_sum += root->val;
        if(c_sum == target) total++;
        
        if(mp.find(c_sum-target) != mp.end())
            total += mp[c_sum-target];
        
        mp[c_sum]++;
        
        util(root->left, c_sum, target);
        util(root->right, c_sum, target);
        
        mp[c_sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        util(root, 0, targetSum);
        mp.clear();
        mp[0] = 1;
        
        return total;
    }
};




// 2 pointer method - O(n^2)
// class Solution {
// public:
//     int total = 0;
    
//     void paths(TreeNode* root, int currSum, int targetSum) {
//         if(!root) return;
//         if(currSum + root->val == targetSum) total++;
        
//         paths(root->left, currSum + root->val, targetSum);
//         paths(root->right, currSum + root->val, targetSum);
//     }
    
//     int pathSum(TreeNode* root, int targetSum) {
//         if(!root) return 0;    
        
//         paths(root, 0, targetSum);
        
//         pathSum(root->left, targetSum);
//         pathSum(root->right, targetSum);
        
//         return total;
//     }
// };