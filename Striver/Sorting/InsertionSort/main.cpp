#include <bits/stdc++.h>
using namespace std;
// takes element and place in appropriate postion
    void insertionSort(vector<int> &arr, int n)
    {
        //write your code here
        for(int i = 1; i <= n-1;i++){
            int key = arr[i];
            int j = i ;
            while(j > 0 && key < arr[j-1]){
                swap(arr[j], arr[j-1]);
                j--;
            }
        }
    }
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    insertionSort(arr, n);
    for(auto x: arr){
        cout << x << " ";
    }
    
    return 0;
}