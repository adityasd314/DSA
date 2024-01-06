#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<long int> lengths(n, 1);
        vector<long int> counts(n, 1);

        long int maxLength = 1;

        for (short i = 0; i < n; i++) {
            for (short prevIndex = 0; prevIndex < i; prevIndex++) {
                if (lengths[prevIndex] + 1 == lengths[i] && nums[prevIndex] < nums[i]) {
                    counts[i] += counts[prevIndex];
                }else if ( lengths[prevIndex] + 1 > lengths[i] && nums[prevIndex] < nums[i]) {
                    lengths[i] = lengths[prevIndex] + 1;
                    counts[i] = counts[prevIndex];
                } 
            }
            maxLength = max(maxLength, lengths[i]);
        }

        return maxLength;
        

    }   
};