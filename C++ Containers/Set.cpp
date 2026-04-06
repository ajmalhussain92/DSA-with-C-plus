#include <iostream>
#include <set>
using namespace std;

template <typename T>
void printSetElements (const set<T>& setName) {
    for (const T& val : setName) {
        cout << val << " ";
    }
    cout << endl;
}

int main () {
	set<int> numbers = {1, 7, 3, 2, 5, 9};

	// Print set elements
	printSetElements (numbers);
	

	/* Sort elements in a set in descending order ----- */

	set<int, greater<int>> nums = {1, 7, 3, 2, 5, 9};

	// Print the elements
	for (int num : nums) {
		cout << num << "\n";
	}


	/* Unique Elements : cannot be duplicated or equal ----- */

	set<string> cars = {"Volvo", "BMW", "Ford", "BMW", "Mazda"};

	// Print set elements
	printSetElements (cars);


	/* Add Elements : .insert() function ----- */

	// Add new elements
	cars.insert ("Tesla");
	cars.insert ("Volvo");           // adding duplicate will be ignored
	cars.insert ("Toyota");
	cars.insert ("Audi");

	// Print set elements
	printSetElements (cars);


	/* Remove Elements : .erase() function ----- */

	// Remove elements
	cars.erase ("Volvo");
	cars.erase ("Mazda");
	
	// Print set elements
	printSetElements (cars);
    

	/* Remove All Elements : .clear() function ----- */

	// Remove all elements
	cars.clear ();
	
	if (cars.empty ()) cout << "Empty set\n"; else printSetElements (cars);
	


	return 0;
}