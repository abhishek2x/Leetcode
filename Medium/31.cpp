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
    
    void sumGrandParents(TreeNode* root, int pt, int gpt) {
        if(!root) return;
        // cout << root->val << " " << pt << " " << gpt << "\n";
        if(!(gpt&1)) sum += root->val;
        sumGrandParents(root->left, root->val, pt);
        sumGrandParents(root->right, root->val, pt);
    }
    
    int sumEvenGrandparent(TreeNode* root) {
        sum=0;
        sumGrandParents(root, -1, -1);
        return sum;
    }
};