class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%nums.size();
        if(k == 0)return;
        vector<int> temp;
        for(int i=n-k;i < n;i++){
            temp.emplace_back(nums[i]);
        }
        
        for(int i=n-1;i >= k;i--){
            nums[i] = nums[i-k];
        }
        for(int i=0;i < k;i++){
            nums[i] = temp[i];
        }


    
    }
};