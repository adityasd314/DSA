#include <bits/stdc++.h>
using namespace std;
vector<int> getFrequencies(vector<int>& v) {
    unordered_map<int, int> mp;
    for(auto x: v){
        mp[x]++;
    }
    int min=v[0], max=v[0];
    for(auto x: v){
        if(mp[min] >= mp[x]){
            if(mp[min] == mp[x]){
                if(x < min){
                    min = x;
                }
            }else{
                min = x;
            }
        }
        if(mp[max] <= mp[x]){
            if(mp[max] == mp[x]){
                if(x < max){
                    max = x;
                }
            }else{
                max = x;
            }
        }
    }
    return {max, min};
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n; i++){
        cin >> nums[i];
    }
    vector<int> ans = getFrequencies(nums);
    for(auto x: ans){
        cout << x << " ";
    }
    return 0;
}