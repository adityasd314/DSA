#include <bits/stdc++.h>
using namespace std;
/*
	The function is called with the parameters:
	quickSort(input, 0, size - 1);

*/

int partitionArray(int input[], int start, int end) {
	// Write your c ode here
	int pivot = input[start];
	int i = start;
	int j = end;
	while(i < j ){
		while(i<=end-1 && input[pivot]<=input[i])
			i++;
		while(j>=start+1 && input[pivot]>input[j])
			j--;
		if(i < j)swap(input[i], input[j]);
	}
	swap(input[start], input[j]);
    return j;

}

void quickSort(int input[], int start, int end) {
	/*
		Don't write main().
		Don't read input, it is passed as function argument.
		Change in the given array itself.
		Taking input and printing output is handled automatically.
	*/
    cout << start << " " << end << endl;
	if(start < end){
		int partition = partitionArray(input, start, end);
		quickSort(input, start, partition - 1);
		quickSort(input, partition + 1, end);
	}
    return;
}
int main(){
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }
    quickSort(arr, 0 , n - 1);
    for(auto x: arr){
    cout << x<< " ";
    }
    return 0;
}