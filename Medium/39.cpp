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
class FindElements {
public:
    
    unordered_map<int, int> mp;
    
    void pureIt(TreeNode* root, int value) {
        if(!root) return;
        
        root->val = value;
        mp[root->val]++;
        
        if(root->left) pureIt(root->left, 2*value + 1);
        if(root->right) pureIt(root->right, 2*value + 2);
    }
    
    FindElements(TreeNode* root) {
       pureIt(root, 0); 
    }
    
    bool find(int target) {
        return mp.find(target) != mp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */