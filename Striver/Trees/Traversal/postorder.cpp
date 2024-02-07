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
    stack<TreeNode*> s;
    vector<int> ans;
    TreeNode* current = root, *temp;
    while(current!=NULL || !s.empty()){
        if(current){
            s.push(current);
            current= current->left;
        }else{
            temp = s.top()->right;
            if(temp == NULL){
                temp = s.top();
                s.pop();
                ans.push_back(temp->data);
                while(!s.empty() && s.top()->right == temp){
                temp = s.top();
                s.pop();
                ans.push_back(temp->data);

                }

            }else{
                current = temp;
            }
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