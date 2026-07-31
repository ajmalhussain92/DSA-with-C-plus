#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int myAtoi (string &s) {
	int sign = 1, ans = 0, i = 0;
	
	// Skip leading spaces
	while (i < s.size() && s[i] == ' ') 
	    i++;
	
	// Read sign
	if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
	    if (s[i++] == '-')
	        sign = -1;
	}
	
	// Read digits
	while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
	    
	    if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && s[i] - '0' > '7')) 
	        return sign == 1 ? INT_MAX : INT_MIN;
	    
	    ans = ans * 10 + (s[i++] - '0');
	}
	
	return sign * ans;
}

int main () {
	string s = "-123";

	cout << myAtoi (s);

	return 0;
};

/*

The rules are:

1. Skip leading spaces

	"    123"  ? 123

2. Read an optional sign

	"+123" ? 123
	"-123" ? -123
	"123"  ? 123

3. Read consecutive digits only
	Stop as soon as you see a non-digit.

	"123abc" ? 123
	"-12gfg4" ? -12

4. Ignore leading zeros

	"000123" ? 123
	"-0012" ? -12

5. If there are no digits, return 0

	"-"
	"+"
	"abc"
	"   -"

	all return 0


6. Clamp (limit) the answer to the 32-bit signed integer range

INT_MAX =  2147483647
INT_MIN = -2147483648


*/