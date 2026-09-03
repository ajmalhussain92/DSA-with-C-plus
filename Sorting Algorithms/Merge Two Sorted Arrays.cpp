#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeArrays (vector<int>& a, vector<int>& b) {
	int n = a.size();
	int m = b.size();

	int i = n - 1, j = 0;

	while (i >= 0 && j < m) {
		if (a[i] > b[j]) {
			swap (a[i], b[j]);
			i--;
			j++;
		}
		else
			break;
	}

	sort (a.begin(), a.end());
	sort (b.begin(), b.end());
}

int main () {
	vector<int> a = {2, 4, 7, 10};
	vector<int> b = {2, 3};

	mergeArrays (a, b);

	for (int x : a) cout << x << " ";
	cout << "\n";
	for (int x : b) cout << x << " ";

	return 0;
}

/*

Merge Two Sorted Arrays Without Extra Space

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output: a[] = [2, 2, 3, 4], b[] = [7, 10] 

Explanation: Combined sorted array = [2, 2, 3, 4, 7, 10], array a[] contains smallest 4 elements: 2, 2, 3 and 4, and array b[] contains remaining 2 elements: 7, 10.


*/