#include <iostream>
using namespace std;

int getSum (int a, int b) {
	while (b != 0) {
		int carry = (a & b) << 1;
		a = a ^ b;
		b = carry;
	}

	return a;
}

int main () {
	int a = 3;
	int b = 5;
	
	cout << getSum (a, b);

	return 0;
}

/*

So:

^ = sum without carry
& = carry generator
<< 1 = move carry to the next bit

Repeat until there are no more carries.



*/