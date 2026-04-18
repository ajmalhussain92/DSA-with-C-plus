#include <iostream>
using namespace std;

// Binary to Decimal Conversion

int bin_dec (int arr[], int n) {
	
    int dec = 0;
    
    for (int i = 0; i < n; i++) {
        dec = dec * 2 + arr[i];
    }
    
    return dec;
}

int main () {
    int arr[] = {1, 0, 1, 1};
    
    int n = sizeof (arr) / sizeof (arr[0]);
    
    int res = bin_dec (arr, n);
    
    cout << "Decimal number = " << res << endl;
    

	return 0;
}