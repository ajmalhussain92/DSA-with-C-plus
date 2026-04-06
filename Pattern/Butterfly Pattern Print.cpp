#include <iostream>
using namespace std;
//Butterfly Pattern Print

int main() {
    
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    // upper part
    for (int i=0; i<n; i++) {	// moves to the next row
    	
    	// left star		// prints column-wise
    	for (int j=0; j<i+1; j++) {
    		cout << "*";
		}
		
		// space 	(i=0,1,2; s=8,6,4; if n=5)
		for (int j=0; j<2*(n-i)-2; j++) {
			cout << " ";
		}
		
		// right star
		for (int j=0; j<i+1; j++) {
			cout << "*";
		}
		
		cout << "\n";
	}
	
	// lower part
    for (int i=0; i<n; i++) {
    	
    	// left star
    	for (int j=0; j<n-i; j++) {
    		cout << "*";
		}
		
		// space 
		for (int j=0; j<2*i; j++) {
			cout << " ";
		}
		
		// right star
		for (int j=0; j<n-i; j++) {
    		cout << "*";
		}
		
		cout << "\n";
	}
    
    return 0;
}
