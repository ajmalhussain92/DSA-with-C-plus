#include <iostream>
using namespace std;

int main() {
    int asciiValue;

    cout << "Enter an ASCII value (0 to 255): ";
    cin >> asciiValue;
    
    if (asciiValue < 0 || asciiValue > 255) {
        cout << "Invalid ASCII value! Please enter a number between 0 and 127." << endl;
        return 1;
    }
    
    // Conversion
    char character = static_cast<char>(asciiValue);
    cout << "The character for ASCII value " << asciiValue << " is: '" << character << "'" << endl;
    
    
    cout << "\n--------------------------------------------\n";
    cout << "Extended ASCII includes 256 characters (0-255)\n";
    cout << "Standard ASCII includes 128 characters (0-127)\n";


    return 0;
}