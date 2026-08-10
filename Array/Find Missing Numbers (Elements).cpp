#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<int> findMissingElements (vector<int>& nums) {
	int mn = INT_MAX, mx = INT_MIN;

	for (int x : nums) {
		mn = min (mn, x);
		mx = max (mx, x);
	}

	vector<bool> seen (mx - mn, false);
	for (int x : nums)
		seen[x - mn] = true;

	vector<int> ans;

	for (int i = mn; i <= mx; i++) {
		if (!seen[i - mn])
			ans.push_back(i);
	}

	return ans;
}

int main () {
	vector<int> arr = {9, 5, 4};

	vector<int> ans = findMissingElements (arr);
	
	for (int x : ans) cout << x << " ";

	return 0;
}

/*

XOR doesn't work here.

Note:
    XOR works for only one missing number
    XOR works for only when the array contains all integers from 1 to n

Examples:
    arr = [1 2 3 4 6]       XOR works
    arr = [3 4 6 8 9]       XOR does not work


*/