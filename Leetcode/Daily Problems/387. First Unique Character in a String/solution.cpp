class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26] = {0};
        vector<int> a;
        for(char c: s){
            arr[c-97]+=1;
            a.push_back(c-97);
        }
        for(int i = 0;i < a.size();i++){
            if(arr[a[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};