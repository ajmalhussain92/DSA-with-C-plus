#include <iostream>
using namespace std;

// ----- Linear Time-Complexity: O(n)

int n = 10;

int main () {
    
    for (int i = 0; i < n; i += 2) {
        cout << i << " ";
    }
    
    for (int i = 0; i < n; i += 3) {
        cout << i << " ";
    }
    
    for (int i = 0; i < n; i += 5) {
        cout << i << " ";
    }
    
    for (int i = 0; i < n / 2; i++) {
        cout << i << " ";
    }
    
    for (int i = 0; i < n / 5; i++) {
        cout << i << " ";
    }
    
    return 0;
}

/*

Incrementing by a constant results in O(n).
i += c (constant)
The loop runs roughly n / c times.

*/