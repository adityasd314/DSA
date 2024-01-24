#include <bits/stdc++.h>
using namespace std;
void f(int index, int sum,vector<int> &sums, int n, int arr[]){
    if(index >= n){
        sums.push_back(sum);
        return;
    }
    f(index + 1, sum, sums, n, arr);

    f(index + 1, sum + arr[index], sums, n, arr);
    
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    vector<int> sums;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    f(0, 0, sums, n, arr);
    sort(sums.begin(), sums.end());
    for(int i: sums){
        cout << i << " ";
    }
    
    return 0;
}