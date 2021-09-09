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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int sum = root->val;
        int lvl=1;
        int curr_lvl=0;
        
        while(!q.empty()) {
            
            int size = q.size();
            int lvl_sum=0;
            curr_lvl += 1;

            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                lvl_sum += node->val;
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(sum<lvl_sum) {
                sum = lvl_sum;
                lvl = curr_lvl;
            }
            // cout << sum << " - " << curr_lvl;
        }
        return lvl;
    }
};