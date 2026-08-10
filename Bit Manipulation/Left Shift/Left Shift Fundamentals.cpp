#include <iostream>
using namespace std;

int main () {
	
	
	

	return 0;
}

/*


number << k

    means:
        Shift the bits of number left by k positions.

---------------------------------------------------
Every bit moved one place left.
A 0 is inserted from the right.
The leftmost bit that moves out is discarded

---------------------------------------------------
Example 1: 5 << 1

First, write 5 in binary (8-bit):

5 = 00000101

Shift left by 1:

Before: 00000101
After : 00001010

Result:

00001010 = 10

So,

5 << 1 = 10

---------------------------------------------------
For positive numbers (when no overflow occurs):
5 << 0 = 5
5 << 1 = 10
5 << 2 = 20
5 << 3 = 40
5 << 4 = 80

Each left shift by one position doubles the value.

---------------------------------------------------
So,

n << k

is equivalent to:

n × 2ᵏ

---------------------------------------------------
Always use this rule: n << k = n × 2ᵏ

Examples:

3 << 2 	= 3 × 2² = 3 × 4 = 12
6 << 3 	= 6 × 2³ = 6 × 8 = 48 
10 << 1 = 10 × 2 = 20

*/