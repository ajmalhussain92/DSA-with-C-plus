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

Add two integers without using the + operator

	a ^ b 		 = adds bits without carry
	(a & b) << 1 = calculates the carry


Repeat until there is no carry.



*/