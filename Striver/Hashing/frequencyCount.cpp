#include <bits/stdc++.h>
using namespace std;

vector<int> countFrequency(int n, int x, vector<int> &nums){
    vector<int> arr(n, 0);
    for(int i = 0;i < nums.size(); i++){
        arr[nums[i]-1]++;
    }
    return arr;

}
int main(){
    int n, x;
    cin >> n>>x;
    vector<int> nums(n);
    for(int i = 0;i < n; i++){
        cin >> nums[i];
    }
    vector<int> ans = countFrequency(n, x, nums);
    for(auto x: ans){
        cout << x << " ";
    }
    return 0;
}