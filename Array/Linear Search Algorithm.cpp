#include<iostream>
using namespace std;
//Linear Search Algorithm	Time Complexity: O(n)
int linearSearch(int* arr, int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main()
{
    int size = 5;
    
    int arr[size] = {1, 2, 3, 4, 5};
    
    cout<<"Array: ";
    for(int i=0; i<size; i++){
        
        cout<< arr[i]<<" ";
    }
    
    int target = 4;
    int res = linearSearch(arr, size, target);
    
    if(res == -1)
    {
        cout <<"\nElement "<<target<<" not found";
    }else
    {
        cout<<"\nElement "<<target<<" found at position "<<res+1;
    }
    return 0;
}
