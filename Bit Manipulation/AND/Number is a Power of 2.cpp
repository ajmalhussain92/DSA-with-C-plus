#include <iostream>
using namespace std;

bool isPowerOfTwo (int x) {

    return x && (!(x & (x - 1)));
}

int main () {
	cout << isPowerOfTwo (2);

	return 0;
}

/*

1	2	4	8	16	32	...


Dry-run:

x = 4

	4 && (!(4 & (4 - 1)))
	
	4 && (!(4 & 3))

	4 && (!0)

	4 && (!false)
	
	4 && true
	
	true && true  =  true


Note:- Any non-zero value = true

*/