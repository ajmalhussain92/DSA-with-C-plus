#include <iostream>
#include <climits>
using namespace std;
//Largest and Smallest Element
//largest element
int findLargest(int *arr, int n){
    int largest = INT_MIN;
    
    for(int i=0; i<n; i++){
        
        if(arr[i] > largest){
            
            largest = arr[i];
        }
    }
    return largest;
}
//smallest element
int findSmallest(int *arr, int n){
    int smallest = INT_MAX;
    
    for(int i=0; i<n; i++){
        
        if(arr[i] < smallest){
            
            smallest = arr[i];
        }
    }
    return smallest;
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
    
    int largest = findLargest(arr, n);
    int smallest = findSmallest(arr, n);
    
    cout<<"Largest element: "<<largest <<endl;
    cout<<"Smallest element: "<<smallest <<endl;
    
    return 0;
}