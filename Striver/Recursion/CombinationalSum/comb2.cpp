#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &nums, int target, int index, vector<int> &ds, vector<vector<int>> &res){
    if(target == 0){
        res.push_back(ds);
        return;
    }
    for(int i = index;i < nums.size();i++){
        if(target > nums[i])break;
        while(i < nums.size() - 1 && nums[i] == nums[i+1])i++;
        ds.push_back(nums[i]);
        solve(nums, target - nums[i], i + 1, ds, res);
        ds.pop_back();
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for(int i=1; i<=n; i++){
        int k;
        scanf("%d", &k);
        nums.push_back(k);
    }
    int target;
    cin >> target;
    vector<vector<int>> res;
    vector<int> ds;
    solve(nums, target, 0, ds, res);
    for (int i = 0; i < res.size(); i++)
    {
        for(auto &x: res[i]){
            cout <<x<< " ";
        }
        cout << endl;
    }
    


}