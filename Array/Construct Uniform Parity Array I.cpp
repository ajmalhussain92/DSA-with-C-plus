#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool uniformArray (vector<int>& nums1) {
    return true;
}

int main () {
    vector<int> nums1 = {2, 4, 7, 10};
    
    cout << uniformArray (nums1);
    
    return 0;
}

/*

odd - odd = even
odd - even = odd

even - odd = odd
even - even = even


But we can compress them into one powerful rule:

	Same parity 		= even result
	Different parity 	= odd result


Intuition: The real LeetCode skill being tested here is not implementation; it's recognizing the parity invariant and realizing there is no impossible case

*/