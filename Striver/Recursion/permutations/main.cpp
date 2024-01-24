#include <bits/stdc++.h>
using namespace std;
void f(vector<int> &ds,int n, bool elementsTaken[], vector<int>&input, vector<vector<int>>  &sol){
    for (int i = 0; i < n; i++)
    {
        if(elementsTaken[i]) continue;
        ds.push_back(input[i]);
        elementsTaken[i] = true;
        if(ds.size() == n){
            sol.push_back(ds);
        }
        f(ds,n,elementsTaken,input,sol);
        elementsTaken[i] = false;

        ds.pop_back();
    }
    
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> sol;
    vector<int> temp;
    bool elementsTaken[n] = {};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    f(temp, n, elementsTaken,a, sol);
    for (auto i : sol)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}