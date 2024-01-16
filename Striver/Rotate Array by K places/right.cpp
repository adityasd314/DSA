#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int size, k;
    cin >> size >> k;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        v.emplace_back(temp);
    }
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int j = 0; j < k; j++)
    {
        v[v.size]
        for (int i = 0; i < v.size() - 1; i++)
        {
            v[i] = v[i + 1];
        }
        v[v.size() - 1] = temp;
        
    }

    return 0;
}