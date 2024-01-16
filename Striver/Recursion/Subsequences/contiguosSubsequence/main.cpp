#include <bits/stdc++.h>
using namespace std;
void subSequence(int index, string s, string ans){
    if(index >= s.length()){
        cout << ans<<endl;
        return;
    }
    subSequence(index+1,s,ans+s[index]);
    subSequence(index+1,s,ans);
}
int main(){
    subSequence(0,"abc","");
    return 0;
}