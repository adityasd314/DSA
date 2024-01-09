#include <bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1, leaves2;
        DFS(root1, leaves1);
        DFS(root2, leaves2);
        return leaves1 == leaves2;
    }

private:
    void DFS(TreeNode* root, vector<int>& leaves) {
        if (root == nullptr)
            return;
        
        if (root->left == nullptr && root->right == nullptr) {
            leaves.push_back(root->val);
            return;
        }

        DFS(root->left, leaves);
        DFS(root->right, leaves);
    }
};
