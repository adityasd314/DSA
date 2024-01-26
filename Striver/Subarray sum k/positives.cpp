int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int i = 0;
    int j = 0;
    long long sum = 0;
    int maxlength = 0;
    while(j<a.size()){
        sum += a[j++];
        if(sum == k){
        maxlength = max(maxlength, j-i);
        }
        while(sum > k && i < j){
            sum -= a[i++];
            if(sum == k){
        maxlength = max(maxlength, j-i);
        }
        }

    }
    return maxlength;
}