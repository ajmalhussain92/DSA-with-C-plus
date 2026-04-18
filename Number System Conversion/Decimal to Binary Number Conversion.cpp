#include <iostream>
#include <cmath>
using namespace std;

// For small numbers

int decimalToBinary (int num) { 
    int binary = 0;			
    int i = 0;				
    
    while (num) {
        binary += (num % 2) * pow(10, i);
        num = num / 2;
        i++;
    }
    
    return binary;
}  

// For large numbers (uses string)

string decimalToBinary (int num) {
    if (num == 0) return "0";
    string binary = "";
    
    while (num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;
    }
    
    return binary;
}


int main () {
    
    int num;
    
    cout << "Enter the Decimal number: ";
    cin >> num;
    
    int res = decimalToBinary (num);
    cout << "Binary of " << num << " is: " << res << endl;
    
    return 0;
}
