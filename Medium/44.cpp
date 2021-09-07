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
    vector<string> masks;
    
    int intVal(string mask) {
        int ans=0;
        int len = mask.length();
        
        for(int i=0; i<len; i++) {
            if(mask[i] == '1'){
                ans += pow(2, (len-i-1));}
        }
        return ans;
    }
    
    void createMasks(TreeNode* root, string mask) {
        if(!root) return;
        
        string c_mask = mask + to_string(root->val);
        if(!root->left && !root->right) {
            if(c_mask != "") masks.push_back(c_mask);
        }
        
        createMasks(root->left, c_mask);
        createMasks(root->right, c_mask);
    }
    
    int sumRootToLeaf(TreeNode* root) {
        masks.clear();
        createMasks(root, "");
        
        int sum=0;
        for(string mask: masks)
            sum += intVal(mask);
        
        return sum;
    }
};