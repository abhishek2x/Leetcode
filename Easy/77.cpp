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
    
    void makeMap(TreeNode* root) {
        if(!root) return;
        makeMap(root->left);
        inorder.push_back(root->val);
        makeMap(root->right);
    }
    
    bool checkSum(int k) {
        int st=0;
        int ed=inorder.size()-1;
        
        while(st<ed) {
            int num = inorder[st] + inorder[ed];
            if(num == k) return true;
            else if(num < k) st++;
            else ed--;
        }
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder.clear();
        makeMap(root);
        return checkSum(k);
    }
};