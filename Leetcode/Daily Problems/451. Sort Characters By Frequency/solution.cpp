class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(const auto &x: s){
            mp[x]++;
        }
       vector<pair<int, char>> v; 
       for(const auto &[x, y]: mp){
           v.push_back({y,x});
       }
       sort(v.begin(), v.end(), [](const pair<int, char> &a,const pair<int, char> &b){
           return a.first > b.first;
       });
       string r;
       for(const auto& [x, y]: v){
           string k(x, y);
           r += k;

       }
       return r;
        
    }
};