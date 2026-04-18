#include <iostream>
using namespace std;

// Octal to Decimal Conversion

int oct_dec (int arr[], int n) {
	
    int dec = 0;
    
    for (int i = 0; i < n; i++) {
        dec = dec * 8 + arr[i];
    }
    
    return dec;
}

int main () {
    int arr[] = {1, 3};
    
    int n = sizeof (arr) / sizeof (arr[0]);
    
    int res = oct_dec (arr, n);
    
    cout << "Decimal number = " << res << endl;
    

	return 0;
}

/*

	*(*((0) * 8 + 7) * 8) + 1

*/