#include <iostream>
#include <vector>
using namespace std;

int maxPathSum (vector<int> &a, vector<int> &b) {
	int n = a.size();
	int m = b.size();

	int maxSum = 0;

	int sum1 = 0;
	int sum2 = 0;

	// Two pointers to iterate over two arrays
	int i = 0;
	int j = 0;

	while (i < n && j < m) {

		if (a[i] < b[j])
			sum1 += a[i++];

		else if (a[i] > b[j])
			sum2 += b[j++];

		else {
			maxSum += max (sum1, sum2);
			sum1 = 0, sum2 = 0;

			while (i < n && j < m && a[i] == b[j]) {
				maxSum += a[i++];
				j++;
			}
		}
	}

	// remaining elements
	while (i < n)
		sum1 += a[i++];

	// remaining elements
	while (j < m)
		sum2 += b[j++];

	maxSum += max (sum1, sum2);

	return maxSum;
}

int main () {
	vector<int> a = {2, 3, 7, 10, 12};
	vector<int> b = {1, 5, 7, 8};

	cout << maxPathSum (a, b);

	return 0;
}