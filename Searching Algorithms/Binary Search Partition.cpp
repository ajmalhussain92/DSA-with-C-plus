#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int kthElement (vector<int>& a, vector<int>& b, int k) {

    // Binary search on the smaller array
    if (a.size() > b.size())
        return kthElement (b, a, k);

    int n = a.size();
    int m = b.size();

    int low = 0;
    int high = n;

    while (low <= high) {

        int cutA = (low + high) / 2;
        int cutB = k - cutA;

        int aL = (cutA == 0) ? INT_MIN : a[cutA - 1];
        int aR = (cutA == n) ? INT_MAX : a[cutA];

        int bL = (cutB == 0) ? INT_MIN : b[cutB - 1];
        int bR = (cutB == m) ? INT_MAX : b[cutB];

        // Correct partition
        if (aL <= bR && bL <= aR) 
            return max(aL, bL);

        // Too many elements taken from a
        else if (aL > bR) 
            high = cutA - 1;

        // Too few elements taken from a
        else 
            low = cutA + 1;
    }

    return -1;
}

int main () {
	vector<int> a = {2, 3, 6, 7, 9};
	vector<int> b = {1, 4, 8, 10};
	
	int k = 5;

	cout << kthElement (a, b, k);

	return 0;
}

/*

Required conditions:
	1. Works on two sorted arrays. 
	2. Both arrays must be sorted in the same order.
	3. The arrays can even be empty, as long as the other array contains the kth element
-------------------------------------------------------------------------
int low = max(0, k - m);
int high = min(k, n);

*/
