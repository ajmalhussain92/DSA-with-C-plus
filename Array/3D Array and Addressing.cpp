#include <iostream>
using namespace std;

// -------------------------------3D Array-------------------------------

int main () {
	int arr[2][3][4] = {
	    {   // First 2D array (i=0)
	        {1, 3, 7, 5},   // row 0 (j=0)
	        {8, 3, 2, 9},   // row 1 (j=1)
	        {4, 6, 1, 0}    // row 2 (j=2)
	    },
	    {   // Second 2D array (i=1)
	        {5, 2, 8, 1},
	        {7, 3, 9, 4},
	        {0, 6, 2, 8}
	    }
	};
	
	cout << *02[arr] << endl;
	
	// Access
	cout << "Elements access: \n";
	for (int i = 0; i < 2; i++) {          		// Loop over i arrays (dimensions)
	    for (int j = 0; j < 3; j++) {      		// Loop over j rows
	        for (int k = 0; k < 4; k++) {  		// Loop over k columns
	            cout << arr[i][j][k] << "\t"; 	// Access element
	        }
	        cout << "\n"; 	// New line after each row
	    }
    	cout << "\n"; 		// Extra newline after each array (dimension)
	}
	
	
	// Another way to organize
	int arr2[2][3][4] = {
        { {1, 3, 7, 5}, {8, 3, 2, 9}, {4, 6, 1, 0} },
        { {5, 2, 8, 1}, {7, 3, 9, 4}, {0, 6, 2, 8} }
    };
	
	
	//Access an element
	cout << "\nThe last element: ";
	cout << arr[1][2][3];
	
	return 0;
}

/* Notes:

	arr[i][j][k] = *(*(*(a + i) + j) + k)
	
	arr[i][j][k] = *(*(*(a + i) + j) + k) = (((base address + i * size of each 2D array) + (j * size of each row)) + k * size of each DT)

	arr[2][3][4] = (((a + 2) + 3) + 4) = (((base address + 2 * size of each 2D array) + (3 * size of each row)) + 4 * size of each DT)
	
	
	size of each 2D array = (R * C) * size of each DT

=================================================================================

3D Array:

	int arr[2][3][4] means:
	
		2 2D arrays
		3 rows in each
		4 columns in each
		
Internally, 1D, 2D, or 3D arrays all are 1D arrays in Memory.

Shortly:

	a[i][j][k] = *(*(*(a + i) + j) + k)
	
	where,
		a = base address (starting address)
		i = skip i no. of 2D arrays
		j = skip j no. of rows 
		k = skip k no. of blocks (indices)


*/