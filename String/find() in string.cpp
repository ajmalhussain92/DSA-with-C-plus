#include <iostream>
using namespace std;


int main () {
    string text = "apple,banana,orange";
    size_t position = text.find(',');
    
    if (position != string::npos) {
        cout << "Comma found at position: " << position << endl;
    } else {
        cout << "Comma not found in the string." << endl;
    }
    
    // --------------------------------------------------------------------------
    
    string s = "apple, banana orange";

    cout << s.find(',') << endl;        // delimiter
    cout << s.find("banana") << endl;   // substring
    cout << s.find('g') << endl;        // character
    
    cout << s.find('z') << endl;        // 18446744073709551615   (on 64-bit system)
    
    
    
    return 0;
}

/*

find () :-

'find ()' can search anything inside a string:

	i) 		single character
	ii) 	substring
	iii) 	delimiter (like ,, *, space)
	iv) 	even another string object

Example Uses:
	text.find(',');
	text.find(' ');
	text.find('*');
	
	text.find("banana");
	text.find("app");
	
	text.find("apple", 5);  	// start searching from index 5
	

'find ()' returns either:
	1. a valid index (0 to length-1), OR
	2. exactly 'string::npos' if not found

-----------------------------------------------------------------------
string::npos = 18446744073709551615 on 64-bit, Which is that maximum size_t value.


*/