using namespace std;

class Solution {
public:
  
    
    string countAndSay(int n) {
        string s = "1";
        int currentCount = 1; 
        while(--n){
            string h = "";
            for (int i = 0; i < s.length(); ++i) {
                char charToCount = s[i];
                while (i + 1 < s.length() && charToCount == s[i + 1]) {
                    currentCount++;
                    i++;
                }
                h += to_string(currentCount) + charToCount;
                currentCount = 1; 
            }
            s = h;
        }
        return s;
    }
};
