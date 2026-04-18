#include <iostream>
using namespace std;

int removeDuplicates(int nums[], int n) {
	int k = 1;		// track duplicates
	
	int temp[n];
	temp[0] = nums[0];	// Assusme first element duplicate
		
	for (int i=1; i<n; i++) {
		if (nums[i] == nums[i-1]) {
			continue;
		} else {
			temp[k] = nums[i]; 
			k++;
		} 
	} 
	
	// in-place
	for (int i=0; i<k; i++) {
		nums[i] = temp[i];
	}
	return k;
}

int main () {
	int n = 5;
	int nums[n] = {1, 2, 2, 5, 7};
	
	int k = removeDuplicates(nums, n);
	
	cout << k << endl;
	
	for (int x: nums) {
		cout << x << " ";
	}
	
	return 0;
}
