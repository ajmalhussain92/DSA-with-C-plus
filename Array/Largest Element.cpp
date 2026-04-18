#include <iostream>
#include <climits>
using namespace std;
//Largest element
int findLargest(int *arr, int n){
    int largest = INT_MIN;
    
    for(int i=0; i<n; i++){
        
        if(arr[i] > largest){
            
            largest = arr[i];
        }
    }
    return largest;
}

int main(){
    
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    
    int arr[n];
    
    cout <<"Enter elements of array:\n";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int res = findLargest(arr, n);
    
    cout<<"Largest element: "<<res;
    
    return 0;
}