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
    int idx;

    void init() {
        idx=0;
        mp.clear();
    }
 
    TreeNode* dowork(vector<int> preorder, int left, int right) {
        if(left > right) return NULL;
        
        int element = preorder[idx++];
        int pivot = mp[element];

        TreeNode* root = new TreeNode(element);
        root->left = dowork(preorder, left, pivot-1);
        root->right = dowork(preorder, pivot+1, right);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        init();
        vector<int> inorder(preorder.begin(), preorder.end());
        sort(inorder.begin(), inorder.end());
        
        for(int i=0; i<inorder.size(); i++) 
            mp[inorder[i]] = i; 

        return dowork(preorder, 0, preorder.size()-1);
    }
};