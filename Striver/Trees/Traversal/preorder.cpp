#include <bits/stdc++.h>
#include <bits/tree.h>
using namespace std;
void printPreorderRecursive(TreeNode* root){
    // root left right
    if(root == NULL) {return;}
    cout << root->data<< " ";
    printPreorderRecursive(root->left);
    printPreorderRecursive(root->right);
}
void printPreorderIterative(TreeNode* root){
    // root left right
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()){
        TreeNode* node = s.top();
        s.pop();
        cout << node->data<< " ";
        if(node->right)s.push(node->right);
        if(node->left)s.push(node->left);


    }
    return;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    printPreorderRecursive(root);
    cout << endl;
    printPreorderIterative(root);
    return 0;
}