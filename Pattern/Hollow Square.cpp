#include <iostream>
using namespace std;
int main(){
   int n;
   cout<<"Enter the no.: ";
   cin>>n;
   
   
    for(int i=0; i<n; i++){
    
        if(i == 0 || i == n-1){			// * on top & bottom
            
            for(int j=0; j<n; j++){
                
                cout<<"*";
            }
        }else{
            cout<<"*";
            //space
            for(int j=0; j<n-2; j++){
                
                cout<<" ";
            }
            cout<<"*";
        }
      cout<<"\n";
    }

    return 0;
}