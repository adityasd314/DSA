class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        short i = 0;
        short j = 0;
        
        while(j <= nums.size() - 1){
            if(nums[j]!=0){
                nums[i++] = nums[j];
            }
            j++;
        }
        while(i < nums.size()){
            nums[i++] = 0;
        }
    }
};