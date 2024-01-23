class Solution {
public:
void f(vector<int> &ds,int n, vector<bool> elementsTaken, vector<int>&input, vector<vector<int>>  &sol){
    for (int i = 0; i < n; i++)
    {
        if(elementsTaken[i]) continue;
        ds.push_back(input[i]);
        elementsTaken[i] = true;
        if(ds.size() == n)
            sol.push_back(ds);
        
        f(ds,n,elementsTaken,input,sol);
        elementsTaken[i] = false;

        ds.pop_back();
    }
    
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
    vector<int> temp;
    vector<bool> elementsTaken(nums.size(), false);

    f(temp, nums.size(), elementsTaken,nums, sol);
    return sol;
    }
};