#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map <string, vector<string>> mp;
        for(const auto &x: strs){
            string s {x};
            ranges::sort(s);
            mp[s].push_back(x);
        }
        for(const auto& [_, x]: mp){
            res.push_back(x);
        }
        return res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    } 
    cout << "sd";
    vector<vector<string>> res =  Solution().groupAnagrams(arr);
    cout << "sd";
    for(auto strarr: res){
        for(auto s: strarr){
            cout << s<< " ";
        }
        cout << endl;
    }


    return 0;
}