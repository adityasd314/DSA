#include <bits/stdc++.h>
using namespace std;
void mergeSort(int arr[],int low,int high)
{
    int mid = (high + low) / 2;
    if(low >= high){
        return;
    }else{
        int temp[high - low + 1];
        int p = low;
        int q = mid;
        for (int i = 0; i < high-low+1; i++)
        {
            if(p >= mid){
                while(q <= high){
                    temp[i++] = arr[q];
                    q++;
                }
                break;
            }
            if(q >= high+1){
                while(p < mid){
                    temp[i++] = arr[p];
                    p++;
                }
                break;
            }
            if(arr[p] < arr[q]){
                temp[i] = arr[p];
                p++;
            }else{
                temp[i] = arr[q];
                q++;
            }
        }
        

        
    }
    mergeSort(arr, 0, mid);
    mergeSort(arr, mid, high);
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr,0, n-1);
    for (auto n : arr)
    {
        cout << n << " ";
    }
    return 0;
}