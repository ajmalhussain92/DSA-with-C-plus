#include <iostream>
#include <sstream>
using namespace std;

int main () {
    string str = "This is a sample sentence";
    
    stringstream ss (str);
    
    string word;
    
    while (ss >> word) {
        cout << word << endl;
    }

    return 0;
}

/*

stringstream:
    It treats whitespace as a delimiter by default, making it easy to extract words.
    A common and straightforward method to split a string into words based on spaces in C++

*/