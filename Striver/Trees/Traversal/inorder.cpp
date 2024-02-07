#include <bits/stdc++.h>
#include <bits/tree.h>
#include <time.h>

using namespace std;
void printInorderRecursive(TreeNode* root){
    // left root right
    if(root == NULL) {return;}
    printInorderRecursive(root->left);
    cout << root->data<< " ";
    printInorderRecursive(root->right);
}
vector<int> printInorderIterative(TreeNode* root){
    // left root right
    stack<TreeNode*> s;
    // s.push(root);
    vector<int> ans;
    TreeNode* node = root;
    while(!s.empty()){
        if(node!=NULL){
            s.push(node);
            node = node->left;
        }else{
            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node = node->right;
        }
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
    printInorderRecursive(root);
    cout << endl;
    cout << endl;
    vector<int> ans = printInorderIterative(root);
    for(auto x: ans)
    {
        cout << x << " ";
    }
    return 0;
}