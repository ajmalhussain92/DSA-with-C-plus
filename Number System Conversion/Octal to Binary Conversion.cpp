#include <iostream>
using namespace std;

// Octal to Binary Conversion

// Process: Octal -> Decimal -> Binary

int oct_bin (int arr[], int n) {
	
    int dec = 0;
    
    // Octal -> Decimal
    for (int i = 0; i < n; i++) {
        dec = dec * 8 + arr[i];
    }
    
    // Decimal -> Binary
    int binary = 0;
    int multiplier = 1;
    
    while (dec != 0) {
    	binary = (dec % 2) * multiplier + binary;
    	
    	dec /= 2;		// base = 2
    	multiplier *= 10;
	}
    
    return binary;
}

int main () {
    int arr[] = {1, 7};
    
    int n = sizeof (arr) / sizeof (arr[0]);
    
    int res = oct_bin (arr, n);
    
    cout << "Binary number = " << res << endl;
    
	return 0;
}