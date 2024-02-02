#include <bits/stdc++.h>
#include <bits/tree.h>
using namespace std;
void printPostorderRecursive(TreeNode* root){
    // root left right
    if(root == NULL) {return;}
    printPostorderRecursive(root->left);
    printPostorderRecursive(root->right);
    cout << root->data<< " ";
}
vector<int>printPostorderIterative(TreeNode* root){
    // left right root
    stack<TreeNode*> s1;
    stack<int> s2;
    vector<int> ans;
    TreeNode* current = root;
    s1.push(current);
    while(!s1.empty()){
        current = s1.top();
        s1.pop();
        s2.push(current->data);
        if(current->left)s1.push(current->left);
        if(current->right)s1.push(current->right);
        
    }

    while(!s2.empty()){
        ans.push_back(s2.top());
        s2.pop();
    }
    return ans;

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
    printPostorderRecursive(root);
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    vector<int> ans = printPostorderIterative(root);
    for(auto x: ans){
        cout << x <<" ";
    }
    return 0;
}