#include <iostream>
using namespace std;

int main () {
	char character;
	
	cout << "Enter any character (to see its ASCII Value): ";
	cin >> character; 
	
	int asciiValue = static_cast<int>(character);
	
	cout << "ASCII Value for character '" << character << "' is: " << asciiValue << endl;
	
	
	cout << "\n--------------------------------------------\n";
	cout << "ASCII: A Character Encoding Standard\n";
	cout << "ASCII = American Standard Code for Information Interchange\n";

	return 0;
}