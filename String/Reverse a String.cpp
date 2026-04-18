#include <iostream>
using namespace std;

// Reverse a String

int main () {
	string str = "XAVIER";
	string revStr;
	
	for (int i = str.length() - 1; i >= 0; i--) {
	    revStr += str[i];
	}
	
	cout << revStr << endl;
	
	return 0;
}