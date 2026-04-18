#include <iostream>
using namespace std;

// Binary to Octal Conversion

// Process: Binary -> Decimal -> Octal

int bin_oct (int arr[], int n) {
	
    int dec = 0;
    
    // Binary -> Decimal
    for (int i = 0; i < n; i++) {
        dec = dec * 2 + arr[i];
    }
    
    // Decimal -> Octal
    int octal = 0;
    int multiplier = 1;
    
    while (dec != 0) {
    	octal = (dec % 8) * multiplier + octal;
    	
    	dec /= 8;		// base = 8
    	multiplier *= 10;
	}
    
    return octal;
}

int main () {
    int arr[] = {1, 1, 1, 1};
    
    int n = sizeof (arr) / sizeof (arr[0]);
    
    int res = bin_oct (arr, n);
    
    cout << "Octal number = " << res << endl;
    

	return 0;
}


/*

For converting any base to binary:

	i) Convert from the source base to decimal.
	ii) Convert from decimal to binary (by dividing by 2 repeatedly).

*/