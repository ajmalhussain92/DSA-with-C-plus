#include<iostream>
using namespace std;
//Hollow Triangle
int main(){
    
    int n;
    cout<<"Enter num: ";
    cin>>n;
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<n-i-1; j++){
            
            cout<<" ";
        }
        cout<<"*";
        
        if(i != n-1){
            for(int j=0; j<2*i-1; j++){
                cout<<" ";
            }
        }else{
            for(int j=0; j<2*i-1; j++){
                cout<<"*";					//for base star
            }
        }
        
        if(i != 0){
            cout<<"*";
        }
        cout<<endl;
    }
    
    return 0;
}
