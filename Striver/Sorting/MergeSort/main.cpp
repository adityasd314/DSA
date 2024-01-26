#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int mid, int r){
    int temp[r-l+1];
    int left = l;
    int right = mid + 1;
    int i = 0;
    while(left <= mid && right <= r){
         if(arr[left] < arr[right]){
            temp[i++] = arr[left++];
        }else{
            temp[i++] = arr[right++];
        }
    }
    while(left <= mid){
            temp[i++] = arr[left++];
       
    }
    while(right <= r){
        
            temp[i++] = arr[right++];
        
    }
    for(int i=l;i <= r;i++){
        arr[i] = temp[i-l];
    }

}
void mergeSort(int arr[], int l, int r) {
    // Write Your Code Here
    if(l>=r)return;
    int mid=l+r/2;
    mergeSort(arr, l,mid);
    mergeSort(arr, mid+1,r);
    merge(arr, l, mid, r);
}

int main(){
    int n;
    cin >> n;
    int arr[100000];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    for(auto x: arr){
        cout << x << " ";
    }
    
    return 0;
}