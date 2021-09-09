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
    unordered_map<int, int> mp;
    int ans;
    
    // init function
    void init() {
        ans=0;
        mp.clear();
    }    
    
    // returns true if it can be rearranged into pallindrome
    bool isPallindrone(unordered_map<int, int> mp) {
        return true;
    }
    
    // helper function
    void helper(TreeNode* root) {
        if(!root) return;
        mp[root->val]++;
        
        // leaf node
        if(!root->left && !root->right){
            int odds=0;
            for(auto it: mp) 
                if(it.second%2) odds++;
            if(odds <= 1) ans++;
        }
        
        helper(root->left);
        helper(root->right);
        mp[root->val]--;
    }
    
    // primary function
    int pseudoPalindromicPaths (TreeNode* root) {
        init();
        helper(root);
        return ans;
    }
};


// SOLUTION 2

class Solution {
public:
    int res = 0;
    int path;
    void dfs(TreeNode *root) {
        // updating path
        path ^= 1 << root->val;
        // checking when in a leaf
        if (!root->left && !root->right) res += !(path & (path - 1));
        // exploring the branches
        if (root->left) dfs(root->left);
        if (root->right) dfs(root->right);
        // backtracking
        path ^= 1 << root->val;
    }
    int pseudoPalindromicPaths(TreeNode *root) {
        dfs(root);
        return res;
    }
};
