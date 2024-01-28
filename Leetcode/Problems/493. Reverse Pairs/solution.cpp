#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int high){
        int mid = (low+high)/2;
        int left = low;
        int right = mid+1;
        vector<int> temp;
        while(left <= mid && right <= high){
            if(nums[left] > nums[right])temp.push_back(nums[right++]);
            else temp.push_back(nums[left++]);
        }
        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);
        for(int i=low;i<=high;i++){
            nums[i] = temp[i-low]; 
        }
    }

    int mergeSort(vector<int>& nums, int low, int high){
        if(low >= high) return 0; // Base case
        int mid = (low+high)/2;
        int count = 0;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1,high);

        // Count inversions
        int left = low;
        int right = mid+1;
        while(left <= mid){
            while(right <= high && nums[left] > 2*nums[right]){
                right++;
            }
            count += (right - mid - 1);
            left++;
        }

        merge(nums, low, high);
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << Solution().reversePairs(nums) << endl;
    return 0;
}
