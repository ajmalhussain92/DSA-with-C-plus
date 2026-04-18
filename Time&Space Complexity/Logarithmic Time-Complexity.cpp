#include <iostream>
using namespace std;

// ----- Logarithmic Time-Complexity: O(log n)

int n = 10;

int main () {
    // i *= c (constant)
    
    for (int i = 1; i < n; i *= 2) {
        // code ...
    }
    
    for (int i = 1; i < n; i *= 3) {
        // code ...
    }
    
    for (int i = 1; i < n; i *= 5) {
        // code ...
    }
    
    
    // i /= c (constant)
    
    while (n > 0) {
        n /= 2;
    }
    
    while (n > 0) {
        n /= 5;
    }
    
    for (int i = 10; i < n; i /= 2) {
        // code ...
    }
    
    for (int i = 10; i < n; i /= 3) {
        // code ...
    }
    
    for (int i = 10; i < n; i /= 5) {
        // code ...
    }
    
    return 0;
}

/*

Multiplying by a constant results in O(log n).
i *= c (constant)

Dividing by a constant reduces the variable exponentially.
Dividing by a constant results in O(log n).
i /= c (constant)

*/