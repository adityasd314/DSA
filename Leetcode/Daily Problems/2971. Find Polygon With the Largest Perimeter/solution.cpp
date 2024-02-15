class Solution {
public:
    long long largestPerimeter(std::vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        priority_queue<int> max_heap(nums.begin(), nums.end());  
        while (!max_heap.empty()) {
            int largest = max_heap.top();
            max_heap.pop();
            sum -= largest;
            if (sum > largest) {
                return sum + largest;
            }
        }
        return -1;
    }
};