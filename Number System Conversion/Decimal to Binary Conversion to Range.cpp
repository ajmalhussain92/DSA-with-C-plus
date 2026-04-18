#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// Decimal to Binary Conversion upto Range
int decimalToBinary (int num) {
    
    int binaryNum = 0, i = 0;
    
    while (num) { 
        int rem = num % 2;
        
        binaryNum += rem * pow (10, i++);		// b + (0*10^0), b + (b*10^1), b + (b*10^2), ...
        
        num /= 2;
    } 
    return binaryNum;
}

void printBinary (int range) {
    
    cout << "Decimal\t\tBinary\n";
    
    for (int i = 0; i <= range; i++) {
        
        cout << i << "\t\t" << decimalToBinary (i) << endl;
    }
}

int main () {
    
    int range;
    
    cout << "Enter the range: ";
    cin >> range;
    
    printBinary (range);
    
    return 0;
}
