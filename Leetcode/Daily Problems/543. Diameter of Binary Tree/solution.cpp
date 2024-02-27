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
    

    int solve(TreeNode* root,int &m) {
         if(root == NULL)return 0;
        int l = solve(root->left, m);
        int r = solve(root->right, m);
        m = max(m, l+r);    
        return 1+max(l, r);
        
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int m = INT_MIN;
        solve(root, m);
        return m;
        
    }
};