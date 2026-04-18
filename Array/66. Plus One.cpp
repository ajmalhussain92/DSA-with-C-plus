#include <iostream>
#include <vector>
using namespace std;


vector<int> plusOne (vector<int>& digits) {
	int n = digits.size();

	for (int i = n - 1; i >= 0; i--) {
		if (digits[i] != 9) {       // If current digit isn't 9
			digits[i] += 1;
			return digits;			// Stop the execution of the function
		} else {                    // If current digit is 9, then current digit becomes 0
			digits[i] = 0;
		}
	}

	digits.insert (digits.begin(), 1);
	return digits;
}

int main () {
	vector<int> digits = {1, 0, 9};

	plusOne (digits);

	for (int x : digits) {
		cout << x << " ";
	}

	return 0;
}