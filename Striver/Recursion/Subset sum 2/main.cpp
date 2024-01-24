#include <bits/stdc++.h>
using namespace std;
void f(int index, vector<int> &temp, vector<int> &arr, vector<vector<int>> &sol)
{
    sol.push_back(temp);
    for (int i = index; i < arr.size(); i++)
    {
        if(i != index && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);

        f(i + 1, temp, arr, sol);
        temp.pop_back();
    }
    
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> sol;
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    f(0, temp, a, sol);
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