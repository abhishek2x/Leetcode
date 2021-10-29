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
    unordered_map<int, vector<pair<int, int>>> mp;
    
    void worker(TreeNode* root, int index, int parent) {
        if(!root) return;
        
        mp[index].push_back({root->val, parent});
        
        worker(root->left, index+1, root->val);
        worker(root->right, index+1, root->val);
    }
    
    bool present(vector<pair<int, int>>& v, int x, int y) {
        
        for(auto it1: v)
            if(it1.first == x)
                for(auto it2: v)
                    if(it2.first == y && it1.second != it2.second)
                        return true;
                    
        return false;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        mp.clear();
        worker(root, 0, -1);
        
        for(auto it: mp) {
            // search for x and y in v
            if(present(it.second, x, y)) return true;
        }
        return false;
    }
};