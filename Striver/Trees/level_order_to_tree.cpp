#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>

/*
Following is the class structure of the Node class:
*/
class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};


Node* createTree(vector<int>&arr){
    // Write your code here.
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    Node* current = q.front();
    for(int i = 1; i < arr.size();i++){
        Node* n = new Node(arr[i]);
        if(!current->left)current->left = n;
        else if(!current->right)current->right = n;
        else{
            q.pop();
            current = q.front();
            i--;
        }
        q.push(n);
    }
    return root;
}
void printTree(Node* root){
    if(root == NULL)return;
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Node* root = createTree(arr);
    // cout << root->data << endl;
    printTree(root);
    return 0;
}
