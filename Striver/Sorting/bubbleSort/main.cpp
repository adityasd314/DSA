#include <bits/stdc++.h>
using namespace std;
// continuosly adj swaps of max till end
void bubbleSort(vector<int>& arr, int n) 
{
    //write your code here

    for(int j = 0; j <= n ;j++){
        bool noswap = true;
        for(int i=0;i <= n-2-j; i++){
        // i i+1
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
            noswap = false;
        }
        if(noswap)break;
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
    bubbleSort(arr);
    
    return 0;
}