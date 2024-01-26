#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    // Write your code here
    long long rem, sum = 0;
    int maxLength = 0;
    unordered_map<long long int, int> prefixSum;
    
    for(int i=0; i < nums.size();i++){
        sum += nums[i];
        if(sum == k)
            maxLength = max(maxLength, i+1);
        rem = sum - k;
        if(prefixSum.find(rem) != prefixSum.end()){
            maxLength = max(maxLength, i - prefixSum[rem]);
        }
        if(prefixSum.find(sum) == prefixSum.end() )
        prefixSum[sum] = i;

    }

    return maxLength;
}