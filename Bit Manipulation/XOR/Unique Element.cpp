#include <iostream>
#include <vector>
using namespace std;

// Unique Element
// ------------------------------------------

// XOR Method (for elements appearing twice)
int singleNumber (const vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

//findUnique
int main () {
	vector<int> nums = {2,2,1};
	
	int xor_res = singleNumber (nums);
	
	cout << "Unique element = " << xor_res << endl;
	
	
	return 0;
}

/* Notes:

1.) XOR Method (for elements appearing twice)

	If every element except one appears exactly twice, XOR of all elements gives the unique element.
	Note: This works when every element appears exactly twice.

2. 


*/