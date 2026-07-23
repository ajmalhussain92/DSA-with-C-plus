#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int countPairs (vector<int> &arr, int target) {
	sort(arr.begin(), arr.end());
	
	int left = 0;
	int right = arr.size() - 1;

	int count = 0;

	while (left < right) {
		int sum = arr[left] + arr[right];

		if (sum < target) {
			left++;
		}
		else if (sum > target) {
			right--;
		}
		else {
			
			// sum == target
			if (arr[left] == arr[right]) {
				int m = right - left + 1;
				count += m * (m - 1) / 2;
				break;
			}

			int leftCount = 1;
			while (left + 1 < right && arr[left] == arr[left + 1]) {
				leftCount++;
				left++;
			}

			int rightCount = 1;
			while (right - 1 > left && arr[right] == arr[right - 1]) {
				rightCount++;
				right--;
			}

			count += leftCount * rightCount;

			left++;
			right--;
		}
	}

	return count;
}

int main () {
	vector<int> arr = {1, 1, 1, 1};
	int target = 2;

	cout << countPairs (arr, target);

	return 0;
}

/*

Input: arr[] = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: Pairs with sum 6 are (1, 5), (1, 5) and (-1, 7).         

Input: arr[] = [1, 1, 1, 1], target = 2
Output: 6
Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1) and (1, 1).

Input: arr[] = [-1, 10, 10, 12, 15], target = 125
Output:  0

---------------------------------------------------------------------------
Combination formula: 
						m * (m - 1) / 2

						where, m = number of items

It counts the number of ways to choose 2 items from n items.

*/