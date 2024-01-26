#include <bits/stdc++.h>
using namespace std;
void selectionSort(vector<int>&arr) {
    // Write your code here.
    int temp, minIndex;
    for(int i = 0;i < arr.size() - 1;i++){
        minIndex = i;
        for(int j = i+1; j < arr.size();j++){
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    
        
    }
    for(auto x: arr){
        cout << x << " ";
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
    selectionSort(arr);
    
    return 0;
}