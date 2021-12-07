// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */



// class Solution {
// public:
    
//     int rob(TreeNode* root){
//         if(!root) return 0;
        
//         queue<TreeNode*> q;
//         q.push(root);
        
//         int levels=0;
//         int o=0, e=0;
        
//         while(!q.empty()) {
//             levels++;
//             int sz = q.size();
//             for(int i=0; i<sz; i++) {
//                 TreeNode* temp = q.front();
                
//                 if(levels%2) o += temp->val;
//                 else e += temp->val;
                
//                 q.pop();
                
//                 if(temp->left)
//                     q.push(temp->left);
//                 if(temp->right)
//                     q.push(temp->right);
//             }
//         }
//         return max(o, e);
//    }
// };