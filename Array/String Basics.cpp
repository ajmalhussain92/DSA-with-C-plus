#include <iostream>
using namespace std;


int main () {
	char ch = 'a';		// Character
	
	char a[10];			// Character array
	
	cout << sizeof(ch) << endl;
	
	cout << sizeof(a) << endl;
	
	
	for (int i=0; i<10; i++) {
		cout << "a[" << i << "] = " << (int)a[i] << endl; // display as int for clarity
	}
	
	cout << endl << a[3] << endl;			// Accessing an element from the uninitialized array leads to undefined behavior.
	
	
	
	// Ways of creating character arrays
	char arr1[] = {'H', 'e', 'l', 'l', 'o'};		// 1st way (No null terminator ('\0') is automatically added.)
	
	char arr2[] = {"Hello"};						// 2nd way	(null terminator ('\0') is automatically added.)
	
	cout << sizeof(arr1) << endl;
	cout << sizeof(arr2) << endl;
	
	int i = 0;
	while (arr2[i] != '\0') {
		cout << arr2[i] << " ";
		i++;
	}
	cout << "\n";
	
	// C++ String
	string arr3 = "Hello";							// Without square []		
	cout << arr3[0] << endl;						// Access a character
	cout << arr3 << endl;							// Access entire character
	
	// Access string like character array
	while (arr3[i] != '\0') {
		cout << arr3[i] << " ";
	}
	
	return 0;
}

/* Notes:

	A character takes 1 byte.
	C++ String is a character array internally.
	C++ String can be accessed using loop or without loop.







*/