#include <iostream>
using namespace std;

int main () {
	
    string str = "leetcode";
    str = str.substr (0, 4);           	// from start
    
    cout << str << endl;				// leet
    
    
    
    string s = "leetcode";
    s = s.substr (4);                 	// from end
    
    cout << s << endl;					// code
    
    return 0;
}

/*

substr() does not modify the original string.

str = str.substr (0, 2); changes the original string.

substr ? copies part into a new string

*/