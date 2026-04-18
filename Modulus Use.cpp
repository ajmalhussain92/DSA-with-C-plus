#include <iostream>
using namespace std;


int main () {
    /* 1. Extracting the last digit: */
	int number = 12345;
	int lastDigit = number % 10;        // lastDigit = 7
	
	/* 2. Hashing or bucketing: */
	int i = 0;
	while (i < 600) {
		cout << i % 5;                  // result is between 0 and 5
		i++;
	}
	
	/* 3. Digit-based algorithms: */
	while (number > 0) {
        int digit = number % 10;        // Extract the last digit
        cout << digit << " ";
        number = number / 10;           // Remove the last digit
    }
	
	return 0;
}

/*

Common use cases:

	1. Extracting the last digit: 
		For any integer, number % 10 gives the last digit.
	
	2. Hashing or bucketing:
		To distribute numbers into buckets (like in hash tables), using number % 10 ensures the result is between 0 and 9, suitable as an index.
	
	3. Digit-based algorithms:
		When processing numbers digit by digit, repeatedly taking % 10 extracts digits from right to left.

*/