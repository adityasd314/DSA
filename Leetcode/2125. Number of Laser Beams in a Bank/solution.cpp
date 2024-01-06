#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
    int previousCount = 0;
    int total = 0;

    for (const std::string& str : bank) {
        int onesCount = std::count(str.begin(), str.end(), '1');

        
        if (previousCount != 0 && onesCount != 0) {
            total += previousCount * onesCount;
            previousCount = 0;
        }

        if (onesCount != 0) {
            previousCount = onesCount;
        } 
    }

    return total;
    }
};