#include <iostream>
using namespace std;

int main() {
    string str1 = "Hello";
    
    cout << "sizeof(str1): " << sizeof(str1) << " bytes" << endl; 
    cout << "Length of string: " << str1.length() << " characters" << endl;
    cout << "Capacity allocated: " << str1.capacity() << " characters" << endl;
    
    
    cout << (10 > 9);
    
    return 0;
}
/*
Pointer to the character array  8
Size (length of string)         8
Capacity (allocated size)       8
Other internal data             8
Total                           32
*/