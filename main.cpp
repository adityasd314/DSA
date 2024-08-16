#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
 
    vector<int> input({1,2,2});
    vector<int> res({2,2,3});
    function<int(int, vector<int>)> solve = [&](vector<int> curr){
        bool isPossible = true;
        for(int i = 0;i < curr.size();i++){
            if(curr[i] > res[i]){
                return false;
            }
            if(curr[i]!)
        }
    };
    cout << solve(0, input);

    return 0;
}
}