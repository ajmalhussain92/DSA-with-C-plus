#include <iostream>
using namespace std;

int main () {
	int arr[] = {1, 4, 15, 27, 34};
	
	int n = sizeof (arr) / sizeof (arr[0]);
	
	bool ascending = true;

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] >= arr[i + 1]) ascending = false;
	}
	
	if (ascending) 
	    cout << "Numbers are Ascending \n";
    else
        cout << "Numbers are not Ascending \n";

	return 0;
}