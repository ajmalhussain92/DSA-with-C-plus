#include <iostream>
#include <vector>
using namespace std;

vector<int> findUnique (vector<int> &arr) {
	int res = 0;
	for (int x : arr)
		res ^= x;

	res &= -res;

	vector<int> ans (2, 0);

	for (int x : arr) {
	    
		if ((x & res) == 0)
			ans[0] ^= x;
		else
			ans[1] ^= x;
	}

	if (ans[0] > ans[1])
		swap (ans[0], ans[1]);

	return ans;
}



int main () {
	vector<int> arr = {1, 2, 3, 2, 1, 4};

	vector<int> ans = findUnique (arr);
	
	for (int x : ans) cout << x << " ";
	
	return 0;
}


/*

Unique Number II

	-> Find two unique element.
	-> Simply XOR all array elements.

*/