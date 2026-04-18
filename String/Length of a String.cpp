#include <iostream>
#include <string>
using namespace std;
//Length of a String

int main() {
    string str;

    // Prompt the user for input
    cout << "Enter a string: ";
    getline(cin, str); // Use getline to allow spaces in the input

    // Calculate the length of the string
    int length = str.length(); // or str.size();

    // Output the result
    cout << "The length of the string \""<<str<<"\" is: " << length << endl;

    return 0;
}
