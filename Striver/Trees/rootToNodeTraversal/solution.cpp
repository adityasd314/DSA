#include <bits/stdc++.h>
#include <bits/tree.h>

using namespace std;
TreeNode* fromVector(const vector<int> &arr ){
    TreeNode* tree(arr[0]);
    bool nodeAtLeft = true;
    TreeNode* p = tree; 
    int depth = 1;
    int goLeft = true;
    for(int i=1;i < arr.size();i++){
        if(!p->left)
            p->left = TreeNode(arr[i]);
        else if(!p->right)
            p->right = TreeNode(arr[i]);
        else if(goLeft){
            p = tree;
            int i = depth;
            while(i >= 0){
                p = p->left;
                i--;
            }
            
        }
    }
    return tree;
}
int main(){
    TreeNode* tree();
    tree->root
    return 0;
}