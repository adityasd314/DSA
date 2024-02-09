class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int>ans(nums.size());  
        ans[0] = 1;   
        int i = 1;
        for(;i < nums.size();i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
       int right = 1;
       i--;
        for(;i >= 0;i--){
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;    
    }
};