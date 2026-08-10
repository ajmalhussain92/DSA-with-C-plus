#include <iostream>
#include <vector>
using namespace std;

int main () {
	string s = "abcdefgh";
	
	cout << s.substr(0) << endl;        // "abcdefgh"
	cout << s.substr(1) << endl;        // "bcdefgh"
	cout << s.substr(3) << endl;        // "defgh"
	cout << s.substr(5) << endl;        // "fgh"
	
	
	cout << s.substr(0, 3) << endl;        // "abc"
	cout << s.substr(0, 5) << endl;        // "abcde"
	cout << s.substr(1, 3) << endl;        // "bcd"
	cout << s.substr(2, 4) << endl;        // "cdef"
	cout << s.substr(3, 5) << endl;        // "defgh"
	

	return 0;
}

/*

Syntax:
    string substr(size_t pos = 0, size_t len = npos) const;
    
    substr (start, length)                      (simple thought)

--------------------------------------------
string s = "abcdefgh";

--------------------------------------------
Example 1: One argument

s.substr(1) = "bcdefgh"
s.substr(2) = "cdefgh"
s.substr(3) = "defgh"
s.substr(5) = "fgh"

Starts at index 3 and goes to the end.

substr(2) 
    Starting index  = 2
    Lenght          = Full length
--------------------------------------------
Example 2: Two arguments

s.substr(0, 3) = "abc"
s.substr(0, 5) = "abcde"
s.substr(1, 3) = "bcd"
s.substr(2, 4) = "cdef"
s.substr(3, 5) = "defgh"

substr(2, 4) 
    Starting index  = 2
    Lenght          = 4 characters

*/