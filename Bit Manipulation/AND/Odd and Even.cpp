#include <iostream>
using namespace std;

int main () {
	
    int n = 5;
    
	if (n & 1)
		cout << "Odd";
	else
		cout << "Even";

	return 0;
}

/*

Every even number has 0 in the last bit.
Every odd number has 1 in the last bit.

*/