#include <iostream>
#include <vector>
using namespace std;

// Time: O(n²), Space: O(n²)
vector<vector<int>> generateSubarrays (vector<int>& arr) {
    int n = arr.size();

    vector<vector<int>> result;

    for (int i = 0; i < n; i++) {
    	
        vector<int> subarray;

        for (int j = i; j < n; j++) {
        	
            subarray.push_back (arr[j]);
            result.push_back (subarray);
        }
    }

    return result;
}

int main () {

	vector<int> arr = {1, 2, 3, 4, 5};

	vector<vector<int>> result = generateSubarrays (arr);

	for (const auto& rows : result) {
		for (const auto& x : rows) {
			cout << x << " ";
		}

		cout << endl;
	}

	return 0;
};

/*

Subarray:
	A subarray is a continuous (contiguous) part of an array.

	Number of Subarrays:	n (n + 1) / 2
		where, 
			n = number of elements in the array (size of the array)

Example:

arr = {1, 2, 3, 4}

All valid subarrays are:

	{1}, {1,2}, {1,2,3}, {1,2,3,4}
	{2}, {2,3}, {2,3,4}
	{3}, {3,4}
	{4}


-------------------------------------------------------------------------
Subsequence (Not necessarily contiguous):
	A subsequence is formed by deleting zero or more elements without changing the original order.
	A subsequence may be a subarray, but a subarray is always a subsequence.

Valid subsequences are:

	{1}, {1,2}, {1,3}, {1,4}, {1,2,4}, {1,3,4}
	{2}, {2,3}, {2,4}
	{3}, {3,4}, {2,3}
	{4}	
	{}

{3,1} Not a subsequence.


*/