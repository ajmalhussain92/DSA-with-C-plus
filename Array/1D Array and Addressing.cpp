#include <iostream>
using namespace std;

// -------------------------------1D Array-------------------------------

int main () {
    int arr[] = {1, 9, 9};
    
    cout << sizeof(arr) << endl;
    
    cout << &arr << endl;
    cout << &arr[0] << endl;        // &arr == &arr[0]    address value is same
    cout << &arr[1] << endl;
    cout << &arr[2] << endl;
    
    cout << "&arr and &arr[0] give the same address" << endl; 
    
    
	cout << 2[arr] << endl;					// arr[2]
	
	// Access
	cout << "Elements access: \n";
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++ ) {
		cout << arr[i] << " ";
	}
    
    return 0;
}

/* Notes:

Array name represents the address of its first element.
Array name = Base address = Starting address of the array = Address of first element.

& = address of 
* = value at

------------------------------------------------------------------------------------------------

	arr[i] = *(arr + i) = *(i + arr) = i[arr]
	
	arr[i] = base address + i * size of each DT
	
	arr[2] = (a + 2) = base address + 2 * size of each DT
	
	arr[2] means skip 2 blocks	
	
Shortly:

	a[i] = *(a + i)

	where,
		a = base address (starting address)
		i = skip i no. of blocks (indices)
		
================================================================================================





*/