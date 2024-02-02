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
            cout << s.top().first->data << ": "<<s.top().second<<endl;
            if(s.top().second == 1){
                s.top().second++;
                ans[s.top().second - 1].push_back(s.top().first->data);
                if(s.top().first->left)s.push({s.top().first->left, 1}); 
                
            }else if(s.top().second == 2){
                s.top().second++;

                ans[s.top().second - 1].push_back(s.top().first->data);
                if(s.top().first->right)s.push({s.top().first->right, 1}); 

            }else{
                ans[s.top().second].push_back(s.top().first->data);
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