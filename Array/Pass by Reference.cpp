#include<iostream>
using namespace std;
//Pass by Reference
void changeArr(int* arr, int n){
    
    for(int i=0; i<n; i++){
        
        arr[i] *= i+1;
    }
}

int main(){
    
    int n = 5;
    
    int arr[5] = {1, 2, 3, 4, 5};
    
    cout<<"Original Array (Before): ";
    for(int i=0; i<n; i++){
        
        cout<< arr[i]<<" ";
    }
    cout << endl;
    
    changeArr(arr, n);
    
    cout<<"Original Array (After): ";
    for(int i=0; i<n; i++){
        
        cout<< arr[i]<<" ";
    }
    
    return 0;
}
