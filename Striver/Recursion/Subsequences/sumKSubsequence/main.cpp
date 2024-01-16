#include <bits/stdc++.h>
using namespace std;
void sumK(int index,int k, int sum, vector<int> sequence,vector<int>temp, vector<vector<int>> &set){
    if(index >= sequence.size()){
        if(sum == k)
        set.push_back(temp);
        return;
    }
    
    sumK(index+1,k, sum, sequence,temp, set);
    temp.push_back(sequence[index]);
    sumK(index+1,k, sum+sequence[index], sequence,temp, set);

    
}
int main(){
    vector<vector<int>> set;
    vector<int> sequence = {1,2,3, -1};
    sumK(0,3,0,sequence ,vector<int>(),  set);
    for(auto v:set){
        for(auto i:v){
            cout << i << " ";
        }
        cout <<endl;
    }
    return 0;
}