#include <iostream>
using namespace std;

int main () {
    string str = "345";
    
    int num = stoi (str);		// string to int
    cout << num << endl;
    
    string s1 = "345";
    string s2 = "35";
    
    if (s1 > s2)				// String comparison is lexicographical.
    	cout << "First is greater." << endl;
    else
    	cout << "Second is greater." << endl;						// true		(it shouldn't, since '4' < '5')
    	
    // To avoid wrong result (convert string to int)
    if (stoi (s1) > stoi (s2))				
    	cout << "First is greater." << endl;						// true
    else
    	cout << "Second is greater." << endl;
    	
	/* char to int */
    string s3 = "sdf78k6cv92";
    num = 0;
    for (int i = 0; i < s3.size(); i++) {
        if (isdigit (s3[i]))
            num = num * 10 + (s3[i] - '0');     // char to int
    }
    
    cout << num << endl;						// 78692
    
    return 0;
}

/*

stoi() throws an exception if the string isn't a valid number.
Always use try-catch blocks to handle potential exceptions gracefully.

-------------------------------------------------------------------------

String comparison is lexicographical => compares strings character by character from left to right.

*/