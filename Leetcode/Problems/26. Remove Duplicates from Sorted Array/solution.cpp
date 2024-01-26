class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i = 0;
	int j = 1;
	while(j <= arr.size() - 1){
		if(arr[i] == arr[j])
			j++;
		else
			{
				arr[++i] = arr[j++];
			}
	}
	return i+1;
    }
};