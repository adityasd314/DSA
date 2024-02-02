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
vector<int> printPreorderIterative(TreeNode* root){
    // root left right
    stack<TreeNode*> s;
    vector<int> preorder;
    s.push(root);
    while(!s.empty()){
        TreeNode* temp = s.top();
        preorder.push_back(temp->data);
        s.pop();
        if(temp->right)s.push(temp->right);
        if(temp->left)s.push(temp->left);
    }
    return preorder;
    
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
    vector<int> ans = printPreorderIterative(root);
    for(auto x: ans){
        cout << x<< " ";
    }
    return 0;
}