#include <iostream>
using namespace std;

int sumOfArray (int arr[], int n) {
    int totalSum = 0;
    
    for (int i = 0; i < n; i++) 
        totalSum += arr[i];
        
    return totalSum;
}

int main () {
    int arr[] = {1, 2, 3, 4};
    
    int n = sizeof (arr) / sizeof (arr[0]);
    
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        
        cout << arr[i] << " ";
    }
    
    int sum = sumOfArray (arr, n);
    
    cout << "\nSum of Array elements: " << sum;
    
    return 0;
}
