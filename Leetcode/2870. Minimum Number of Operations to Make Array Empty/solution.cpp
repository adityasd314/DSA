#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
 unordered_map<int, int> mpp;
     for (auto it : nums) {
        mpp[it]++;
    }
    int count = 0;

    for (auto it : mpp)
    {
        while (it.second % 3 != 0 && it.second>0)
        {
            it.second -= 2;
            count += 1;
        }
        
        if (it.second % 3 == 0)
        
            count += it.second / 3;
        else
            return -1;
        
    }    
    return count;
    }
};