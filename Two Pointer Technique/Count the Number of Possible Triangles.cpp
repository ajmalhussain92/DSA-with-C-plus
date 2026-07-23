#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int countTriangles (vector<int> &arr) {
	sort (arr.begin(), arr.end());
	int count = 0;

	for (int i = 2; i < arr.size(); ++i) {

		int left = 0, right = i - 1;

		while (left < right) {

			if (arr[left] + arr[right] > arr[i]) {

				count += right - left;

				// Move the right pointer to check smaller pairs
				right--;
			}
			else {

				// Move the left pointer to increase the sum
				left++;
			}
		}
	}

	return count;
}

int main () {
	vector<int> arr = {4, 6, 3, 7};
	
    cout << countTriangles (arr);

	return 0;
}

/*

Input: arr[] = [4, 6, 3, 7]
Output: 3
Explanation: There are three triangles possible [3, 4, 6], [4, 6, 7] and [3, 6, 7]. 
Note that [3, 4, 7] is not a possible triangle.  

Input: arr[] = [10, 21, 22, 100, 101, 200, 300]
Output: 6
Explanation: There can be 6 possible triangles: 
[10, 21, 22], [21, 100, 101], [22, 100, 101], [10, 100, 101], [100, 101, 200] and [101, 200, 300]

Input: arr[] = [1, 2, 3]
Output: 0
Examples: No triangles are possible.


*/