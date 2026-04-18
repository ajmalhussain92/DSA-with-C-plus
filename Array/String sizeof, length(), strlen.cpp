#include <iostream>
#include <string.h>     // for strlen()
using namespace std;

int main() {
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << strlen (alphabet) << endl;   // 26
	cout << sizeof (alphabet) << endl;   // 27  sizeof also includes the \0 character 
	
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	cout << str.length () << endl;      // 26
	cout << str.size () << endl;        // 26
	cout << sizeof (str) << endl;       // 32
	
    char s1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    cout << strlen (s1) << endl;
    cout << s1 << endl;
    
	return 0;
}

// sizeof(str) returns 32 bytes because that's the size of the std::string object in memory on your system.