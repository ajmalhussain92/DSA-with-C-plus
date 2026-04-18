#include <iostream>
#include <vector>
using namespace std;

string reverseString (string str) {
    vector<char> temp;			// vector of char
    
    // store each char to vector from start of str
    for (int i = 0; i < str.length(); i++) {
        temp.push_back (str[i]);
    } 
    
    // string from end to start vector traversal
    string revStr;
    for (int i = temp.size(); i >= 0; i--) {
        revStr += temp[i];
    }
    
    return revStr;
}

int main () {
    string str = "apple";
    string revStr = reverseString (str);
    
    cout << "Reversed string: " << revStr << endl;
    return 0;
}