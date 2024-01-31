#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
string trimFromIndex(const string& str, size_t index) {
    if (index >= str.length()) {
        return "";
    }
    return str.substr(index);
}
    bool isMatch(string s, string p) {
            int i = 0;
            int j = 0;
            bool result = false;
            char nextChar;
            unordered_map<char, vector<int>> chars;
            while(i < s.size() && j < p.size()){
                if(p[j] == '?'){
                    i++;
                    j++;
                }else if(p[j]>='a' && p[j]<='z'){
                    if(chars.find(p[j])!=chars.end()){
                        for(auto x: chars[p[j]]){
                            cout << x << p[j] << " ;"<<endl;
                            if(isMatch(trimFromIndex(s, i), trimFromIndex(p, x+1)))
                                return true;
                        }
                    }
                    if(p[j] == s[i]){
                        i++;j++;
                    }else{
                        return false;
                    }
                }else{
                    if(j == p.size() - 1)return true;
                    nextChar = p[j+1];
                    while(i<s.size() && s[i] != nextChar){
                        i++;
                    }
                    if(i == s.size())return false;
                    chars[nextChar].push_back(j);
                    j++;
                }
            }
            while(j < p.size() && p[j] == '*'){
                if(j == p.size() - 1)return true;
                j++;

            }
            if(i == s.size() && j == p.size())return true;
            
            return result;
    }
};

int main(){
    string s, p;
    cin >> s >> p;
    cout << Solution().isMatch(s, p);
    return 0;
}