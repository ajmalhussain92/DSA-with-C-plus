#include <iostream>
using namespace std;

// -------------------------------2D Array-------------------------------

int main () {
	int arr[2][4] = {
						{1, 3, 7, 5},
						{8, 3, 2, 9}
					};
	
	cout << *02[arr] << endl;
	
	// Access
	cout << "Elements access: \n";
	for (int i = 0; i < 2; i++ ) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	
	//Access an element
	cout << "\nThe last element: ";
	cout << arr[1][3];
	
	return 0;
}

/* Notes:

	arr[i][j] = *(*(a + i) + j))
	
	arr[i][j] = base address + (i * size of each row) + (j * size of each DT)

	arr[2][3] = ((a + 2) + 3) = (base address + 2 * size of each row) + (3 * size of each DT)
	
	arr[2][3] means skip 2 rows, and skip 3 blocks (columns)

=================================================================================

2D Array:

Dimension is always in the form of : [row x column]
[4 x 3] means 4 rows and 3 columns

Shortly:

	a[i][j] = *(*(a + i) + j)
	
	where,
		a = base address (starting address)
		i = skip i no. of rows


*/