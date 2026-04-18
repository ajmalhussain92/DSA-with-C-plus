#include <iostream>
using namespace std;

bool isPalindrome (int x) {
	int k = x;
	int num = 0;
	x = abs(x);
	while (x != 0) {
		num = num * 10 + x % 10;

		x /= 10;
	}
	if (num == k) {
		if (k < 0) {
			return false;   // Check if minus value
		}
		return true;
	} else {
		return false;
	}
}



int main () {

	bool res = isPalindrome (-909);
	
	cout << res;

	return 0;
}