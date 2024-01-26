class Solution {
public:
    void algo(vector<int>& nums, int low, int mid, int high){
        while(mid <= high)
        {if(nums[mid] == 0){
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }else if(nums[mid] == 1){
            mid++;
        }else{
            swap(nums[mid], nums[high]);
            high--;
        }
        }


    }
    void sortColors(vector<int>& nums) {
        int map[3] = {0};
        for(int i=0;i < nums.size();i++){
            map[nums[i]]++;
        }
        int k = 0;
        for(int i=0;i<map[0];i++){
            nums[k++] = 0;
        }
        for(int i=0;i<map[1];i++){
            nums[k++] = 1;
        }
        for(int i=0;i<map[2];i++){
            nums[k++] = 2;
        }

    }
};