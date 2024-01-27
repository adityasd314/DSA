#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void swapIf(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    if (nums1[m] > nums2[n]) {
        swap(nums1[m], nums2[n]);
    }
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int gap = max(1, (m + n) / 2); 
    int i, j;

    while (gap > 0) {
        for (i = 0; i + gap < m; ++i) {
            swapIf(nums1, i, nums1, i + gap);
        }
        
        for (j = gap > m ? gap - m : 0; i < m && j < n; ++i, ++j) {
            swapIf(nums1, i, nums2, j);
        }

        if (j < n) {
            for (j = 0; j + gap < n; ++j) {
                swapIf(nums2, j, nums2, j + gap);
            }
        }
        
        if(gap == 1)break;
        gap = ceil(gap / 2.0);
    }
    
    for (int i = 0; i < n; ++i) {
        nums1[m + i] = nums2[i];
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<int> nums1(m + n);
    vector<int> nums2(n);
    
    for (int i = 0; i < m; ++i) {
        cin >> nums1[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> nums2[i];
    }
    
    merge(nums1, m, nums2, n);
    
    for (int i = 0; i < m + n; ++i) {
        cout << nums1[i] << " ";
    }
    
    return 0;
}
