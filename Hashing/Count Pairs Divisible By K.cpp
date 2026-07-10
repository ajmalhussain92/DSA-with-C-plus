#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int countKdivPairs (vector<int>& arr, int k) {

	unordered_map<int, int> mp;

	int count = 0;

	for (int num : arr) {

		int rem = ((num % k) + k) % k;

		int need = (k - rem) % k;

		count += mp[need];

		mp[rem]++;
	}

	return count;
}

int main () {
	vector<int> arr = {2, 2, 1, 7, 5, 3};
	int k = 4;

	cout << countKdivPairs (arr, k);

	return 0;
}

/*

Complexity
	Time: O(n)
	Space: O(k) (or O(min(n, k)) when using a map)



int rem = ((num % k) + k) % k;		for both positive and negative numbers
int rem = num % k;					only for positive numbers


*/