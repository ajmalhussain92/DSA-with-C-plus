#include <iostream>
#include <climits>
using namespace std;
//Second Largest Element

int findSecondLargest(int* arr, int n){
    if(n<1){
        return INT_MIN;
    }
    int first = INT_MIN, second = INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]>first){
            second = first;
            first = arr[i];
        }else if(arr[i] > second && arr[i] != first){
            second = arr[i];
        }
    }
    return second;
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
    int res = findSecondLargest(arr, n);
    if(res == INT_MIN){
        cout<<"Array must have at least two elements!";
    }else{
        cout <<"Second Largest Element: "<<res;
    }
    
    return 0;
}