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
    
    TreeNode* utility(vector<int>& nums, int l, int r) {
        if(l>r) return NULL;
        
        int idx = (l+r)/2;
        cout << idx << " ";
        TreeNode* newNode = new TreeNode(nums[idx]);
        
        newNode->left = utility(nums, l, idx-1);
        newNode->right = utility(nums, idx+1, r);
        
        return newNode;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        return utility(nums, l, r);
    }
};