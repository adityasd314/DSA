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

    vector<vector<int>>printAllIterative(TreeNode* root){
        // left right root
        vector<vector<int>> ans(3, vector<int>());
        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        while(!s.empty()){
            TreeNode* t= s.top().first;
            int num= s.top().second;
           
            if(num == 1){
                ans[num-1].push_back(t->data);
                s.top().second++;
                if(t->left)
                s.push({t->left, 1});
            }else if(num == 2){
                ans[num-1].push_back(t->data);
                s.top().second++;
                if(t->right)
                s.push({t->right, 1});

            }else{
                ans[num-1].push_back(t->data);
                s.pop();
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
        vector<vector<int>> ans = printAllIterative(root);
        for(auto x: ans){
            for(auto y: x){
            cout << y<<">>";
        }
            cout << endl;
        }
        return 0;
    }