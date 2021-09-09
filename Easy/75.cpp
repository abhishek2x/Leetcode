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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        
        // <val, level>
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        // <level, <sum, count>>
        map<int, pair<double, double>> mp;

        while(!q.empty()) {
            auto top = q.front();
            q.pop(); 
            
            TreeNode* node = top.first;
            int val = node->val;
            int level = top.second;
            
            mp[level].first += val;
            mp[level].second += 1;
            
            if(node->left) q.push({node->left, level+1});
            if(node->right) q.push({node->right, level+1});
        }
        
        for(auto it: mp)
            ans.push_back((it.second.first/it.second.second));
        
        return ans;
    }
};