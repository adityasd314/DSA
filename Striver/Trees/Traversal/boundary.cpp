#include <bits/stdc++.h>
#include <bits/tree.h>
using namespace std;
void printPostorderRecursive(TreeNode *root)
{
    // root left right
    if (root == NULL)
    {
        return;
    }
    printPostorderRecursive(root->left);
    printPostorderRecursive(root->right);
    cout << root->data << " ";
}
void inorder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    inorder(root->left, ans);
    if (root->left == NULL && root->right == NULL)
        ans.push_back(root->data);
    inorder(root->right, ans);
}
vector<int> traverseBoundary(TreeNode *root)
{
    if(!root)return vector<int>();
    TreeNode *p = root;
    vector<int> ans;
    while (p->left || p->right)
    {
        while (p->left)
        {
            ans.push_back(p->data);
            p = p->left;
        }
        
        if (p->right != nullptr)
            p = p->right;
    }
    inorder(root, ans);
    p = root->right;
    while (p->right)
    {
        ans.push_back(p->data);
        p = p->right;
    }
    return ans;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    printPostorderRecursive(root);
    cout << endl;
    cout << endl;
    cout << "Ads";

    vector<int> ans = traverseBoundary(root);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}