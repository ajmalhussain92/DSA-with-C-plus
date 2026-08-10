#include <iostream>
using namespace std;

bool isPower (int n) {
    if (n > 0 && (n & (n - 1)) == 0)
        return true;
    
    return false;
}

int main () {
    int n = 4;
    
	cout << isPower (n);

	return 0;
}

/*

if (n > 0 && (n & (n - 1)) == 0)

--------------------------------------
Power of 2 = 1, 2, 4, 8, 16, ...

*/