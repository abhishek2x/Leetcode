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
    unordered_map<string, pair<int, TreeNode*>> mp;
    vector<TreeNode*> ans;
    
    void init(){
        mp.clear();
        ans.clear();
    }
    
    string postOrder(TreeNode* root) {
        if(!root) {
            return "$";
        }
        
        string left = postOrder(root->left) + "L";
        string right = postOrder(root->right) + "R";
        
        // Now middle
        string str = left + to_string(root->val) + right;
        mp[str].first++;
        mp[str].second = root;
        
        return str;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        init();
        postOrder(root);
        
        for(auto it: mp) {
            // cout << it.first << " -> " << it.second.first << "\n";
            if(it.second.first>1) ans.push_back(it.second.second);
        }
        return ans;
    }
};