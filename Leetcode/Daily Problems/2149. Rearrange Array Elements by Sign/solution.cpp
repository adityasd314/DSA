class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0;
        int j = 1;
        for(int p=0;p < nums.size();p++){
            if(nums[p] < 0){
                ans[j] = nums[p];
                j+=2; 
            }else{
                ans[i] = nums[p];
                i+=2; 
            }
        }
        return ans;
    }
};