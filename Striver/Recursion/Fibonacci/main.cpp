#include <bits/stdc++.h>
using namespace std;
int fibn(int t){
    if(t <= 1)return 1;
    return fibn(t-1) + fibn(t-2);
}
int main(){
    int n = 5;
    cout << fibn(n);
    return 0;
}