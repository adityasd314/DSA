class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        for(const int &x: nums){
            if(count == 0){
                majority = x;
            }
            if(x == majority)count++;
            else count--;
        }
        return majority;
    }
};