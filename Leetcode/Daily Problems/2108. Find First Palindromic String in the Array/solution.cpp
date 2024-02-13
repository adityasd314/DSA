class Solution {
public:
    bool isPalindrome(string &s){
        int left = (s.size()-1)/2;
        int right = left + (s.size()-1)%2;
        while(left >=0 && right <= s.size() - 1){
            if(s[left]  != s[right])return false;
            left--;
            right++;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto &x: words){
            if(isPalindrome(x))return x;
        }
        return "";
    }
};