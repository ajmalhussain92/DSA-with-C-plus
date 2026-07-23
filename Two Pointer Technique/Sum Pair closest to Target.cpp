#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

vector<int> sumClosest (vector<int> &arr, int target) {

	sort (arr.begin(), arr.end());

	int left = 0;
	int right = arr.size() - 1;

	int minDiff = INT_MAX;
    vector<int> res;

	while (left < right) {
		int sum = arr[left] + arr[right];
		int diff = abs (sum - target);
		
		if (diff < minDiff) {
            minDiff = diff;
            res = {arr[left], arr[right]};
        }
        else if (diff == minDiff) {

            if (arr[right] - arr[left] > res[1] - res[0])

                res = {arr[left], arr[right]};
        }

        if (sum < target)
            left++;
        else
            right--;
	}

	return res;
}

int main () {
	vector<int> arr = {5, 2, 7, 1, 4};
	int target = 10;

	vector<int> res = sumClosest (arr, target);
	
	for (int x : res) cout << x << " ";
	
	return 0;
}

/*

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]

Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]

*/