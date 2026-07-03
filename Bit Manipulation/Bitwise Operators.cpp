#include <iostream>
#include<typeinfo>
using namespace std;
//Bitwise Operators

int main() {
    
    // Bitwise & (AND)
    cout << (4 & 8) << endl;        // output: 0
    
    
    // Bitwise | (OR)
    cout << (4 | 8) << endl;        // output: 12
    
    
    // Bitwise ^ (XOR)
    cout << (4 ^ 8) << endl;        // output: 12
    
    cout << (5 ^ 5) << endl;		// output: 0		(Note:- XOR of two same value is always zero.)
    
    // Bitwise ~ (NOT)
    cout << (~ 5) << endl;        	// output: 12 (Inverts bits)
    
    // Bitwise << 	(Left shift)
    int n = 4, i = 1;
    cout << (n << i) << endl;			//output: 8
    
    // Bitwise >> 	(Right shift)
    cout << (n >> i) << endl;			//output: 2


	( n > i)?  cout<<"N is greater": cout<<"N is smaller";
    
    return 0;
}

/*

Bit Manipulation:
	Bit Manipulation in Data Structures and Algorithms (DSA) is the technique of performing operations directly on the binary representation (bits) of numbers.
	Since computers store data as bits (0s and 1s), manipulating bits is often faster and more memory-efficient than using normal arithmetic operations.




*/

