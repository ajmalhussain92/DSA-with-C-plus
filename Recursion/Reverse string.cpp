#include <iostream>
using namespace std;

string rev_str (string str) {
    // base case
    if (str.empty()) return ""; 
    
    return rev_str (str.substr (1)) + str[0];
}

int main () {
	string res;
	cout << rev_str ("ABC");
	
	
	return 0;
}