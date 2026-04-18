#include <iostream>
using namespace std;

int main () {

    string str = "leetcode";
    str.erase (0, 4);           	// from start
    
    cout << str << endl;			// code
    
    
    string text = "drum";
    
    text.erase (1, 1);           	// delete one specific character
    
    cout << text << endl;			// dum
    
    
    string s = "leetcode";
    s.erase (4);              		// from end
    
    cout << s << endl;				// leet

    return 0;
}

/*

erase() modifies the original string.

erase ? cuts from the same string

After 'erase (index, 1)' remaining elements automatically shift one position to the left to fill the gap

*/