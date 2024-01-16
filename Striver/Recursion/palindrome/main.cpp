#include <bits/stdc++.h>
using namespace std;

bool f(string s, int index, int n){
    if(s[index] != s[n-index - 1])return false;
    if(index >= n/2)
    return true;
    return f(s, index+1, n);
    
}
int main(){
    string s = "adida";

    bool palindrome = f(s, 0, s.size());
    cout << s << " is a palindrome: " << palindrome << endl;
    return 0;
}