#include <iostream>
using namespace std;

// Direct XOR of all numbers from 1 to n
int computeXOR (int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    
    return 0;
}

int main () {
    int n = 1;
    cout << computeXOR (n) << endl;
    
    return 0;
}