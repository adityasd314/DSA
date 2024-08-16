#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &nums, int target, int index, int sum, vector<int> &ds, vector<vector<int>> &res){
    if(index == nums.size()){
        if(sum == target){
            res.push_back(ds);
        }
        return;
    }
    if(sum>target){
        return;
    }
    ds.push_back(nums[index]);
    solve(nums, target, index, sum+nums[index], ds, res);
    ds.pop_back();
    solve(nums, target, index+1, sum, ds, res);
}
int main(){
    int n;
    cin >> n;
    vector<string> nums;
    for(int i=1; i<=n; i++){
        int k;
        scanf("%d", &k);
        nums.push_back(k);
    }
    int target;
    cin >> target;
    vector<vector<int>> res;
    vector<int> ds;
    solve(nums, target, 0,sum, ds, res);


}