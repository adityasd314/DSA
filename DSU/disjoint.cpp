#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    int n;
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DisjointSet(int n) :n(n)
    {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    };
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int up = findUPar(u);
        int vp = findUPar(v);
        if (up == vp)
            return;
        if (rank[up] < rank[vp])
        {
            parent[up] = vp;
        }
        else if (rank[up] > rank[vp])
        {
            parent[vp] = up;
        }
        else
        {
            rank[up]++;
            parent[vp] = up;
        }
    }
    void unionBySize(int u, int v)
    {
        int up = findUPar(u);
        int vp = findUPar(v);
        if (up == vp)
            return;
        if (rank[up] < rank[vp])
        {
            parent[up] = vp;
            size[vp] += size[up];
        }
       
        else
        {
            size[up] += size[vp];

            parent[vp] = up;
        }
    }
};
int main(){
 DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";

    ds.unionBySize(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n";
    }
    else cout << "Not same\n";
    return 0;
    return 0;
}