#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main () {

	int a[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};        // coins or notes

	int size = sizeof(a) / sizeof(a[0]);

	// sort (a, a + size);

	int target = 39;

	for (int i = size - 1; i >= 0; i--) {
		while (target >= a[i]) {
			target -= a[i];
			cout << a[i] << " coin used\n";					// do what ever you want here
		}
		
		if (target == 0) break;
	}

	return 0;
}

/*

Coin Change using Greedy approach:
	1. Sort
	2. Compare and subtract larger coins from target

Note:- Coin system is canonical (for Indian currency only)

*/