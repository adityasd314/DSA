#include <bits/stdc++.h>
using namespace std;

void f(int a[], int index, int n){
    if(index >= n/2)
    return;
    swap(a[index], a[n-index-1]);
    f(a, index+1, n);
}
int main(){
    int a[] = {1,2,3,5, 6,7};
    int arraySize = sizeof(a) / sizeof(a[0]);

    f(a, 0, arraySize);
    for(auto i: a){
        cout << i <<" ";
    }
    return 0;
}