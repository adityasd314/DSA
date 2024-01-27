#include <bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    unordered_map<int , vector<int>> mp;
    int x = 0;
    int count = 0;
    for(int i=0;i < a.size();i++){
        x ^= a[i];
        if(x == b)
            count++;
        
        if(mp.find(x^b)!=mp.end()){
            count += mp[x^b].size();
        }
        if(mp.find(x)!=mp.end()){   
            mp[x].push_back(i);
        }else{
            mp[x] = vector<int>{1};
        }
    }
    return count;
}
int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        /* code */
        cin >> a[i];
    }
    cout << subarraysWithSumK(a,k);
    
    return 0;
}