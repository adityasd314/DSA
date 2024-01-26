#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int> &a)
{
    // Write your code here.
    int maxLeader = a[a.size() - 1];
    vector<int> leaders{maxLeader};
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] > maxLeader)
        {
            maxLeader = a[i];
            leaders.push_back(maxLeader);
        }
    }
    return leaders;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int x : superiorElements(a))
    {
        cout << x << " ";
    }
    return 0;
}
