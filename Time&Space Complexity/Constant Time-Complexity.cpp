#include<iostream>
using namespace std;
//Constant Time-Complexity: O(1)
int main(){
    int arr[] = {1, 4, 7};
    int x = 3, y = 70;
    int z = x*y-x*30/80+5000*325-90/78;
    
    int a,b;
    cin>>a>>b;
    
    int sum = a+b;		
    int sub = a-b;
    int mul = a*b;
    
    cout<<sum << endl;
    cout<<sub << endl;
    cout<<mul << endl;
    
    cout << z << endl;
    cout << 3*4 << endl;
    cout << arr[1] << endl;
    cout << x*5 << endl;
    cout << arr[1]-2 << endl;
    
    return 0;
}