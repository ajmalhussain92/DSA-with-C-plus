#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int countPairs (vector<int> &arr, int target) {
	int n = arr.size();

	sort (arr.begin(), arr.end());
	
	int left = 0;
	int right = n - 1;
	
	int count = 0;

	while (left < right) {

		int sum = arr[left] + arr[right];

		if (sum < target) {
		    count += (right - left);
		    left++;
		}
		else
		    right--;
	}

	return count;
}

int main () {
	vector<int> arr = {7, 2, 5, 3};
	int target = 8;

	cout << countPairs (arr, target) << endl;
	return 0;
}