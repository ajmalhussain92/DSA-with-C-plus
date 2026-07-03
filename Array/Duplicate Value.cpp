#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate (vector<int>& nums) {
	unordered_set<int> seen;
	
	for (int x : nums) {
	    if (seen.count (x))
	        return true;
	   
	   seen.insert (x);
	}
	
	return false;
}

int main() {
	vector<int> arr = {1, 2, 3, 4, 5};

	cout << containsDuplicate (arr);

	return 0;
}

/*

For unordered_set, duplicates are not allowed, so count() is always 0 or 1.

*/