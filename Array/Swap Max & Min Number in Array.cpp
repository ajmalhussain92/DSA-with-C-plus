#include<iostream>
#include<climits>
using namespace std;
//Swap Max & Min Number in Array
void swapMaxMin(int* arr, int size){
    
    int largest = INT_MIN, smallest = INT_MAX;
    int lrgIdx, smlIdx;
    
    for(int i=0; i<size; i++){
        
        if(arr[i] > largest){
            largest = arr[i];
            lrgIdx = i;
        }
    }
    
    for(int i=0; i<size; i++){
        
        if(arr[i] < smallest){
            smallest = arr[i];
            smlIdx = i;
        }
    }
    //swap
    swap(arr[lrgIdx], arr[smlIdx]);
}

int main()
{
    int size = 5;
    
    int arr[size] = {20, 60, 100, 40, 150};
    
    cout<<"Array: ";
    for(int i=0; i<size; i++){
        
        cout<< arr[i]<<" ";
    }
    
    swapMaxMin(arr, size);
    
    cout<<"\nArray Swapped Max & Min: ";
    for(int i=0; i<size; i++){
        
        cout<< arr[i]<<" ";
    }
    
    return 0;
}
