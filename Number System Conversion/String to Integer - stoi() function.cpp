#include <iostream>
using namespace std;

int main () {
    string str = "345";
    
    int num = stoi (str);
    
    cout << num << endl;
    
    return 0;
}

/*

stoi() throws an exception if the string isn't a valid number.
Always use try-catch blocks to handle potential exceptions gracefully.

*/