#include <iostream>
#include <climits>
using namespace std;
//Smallest Element
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
    
    int res = findSmallest(arr, n);
    
    cout<<"Smallest element: "<<res;
    
    return 0;
}