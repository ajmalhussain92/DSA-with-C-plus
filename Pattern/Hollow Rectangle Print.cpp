#include <iostream>
using namespace std;
//Hollow Rectangle Print



int main() {
    
    int l, w;
    cout<<"Enter length: ";
    cin>>l;
    cout<<"Enter width: ";
    cin>>w;
    
    
    for(int i=0; i<l; i++){
        
        cout << "*";
        
        if(i == 0 || i == l-1){     // top & bottom prints star
            for(int j=0; j<w-2; j++){
            
            cout << " *";
            }
        }else{
            for(int j=0; j<2*w-4; j++){
                
                cout << " "; 
            }
                
        }

        cout << " *";
        
        cout << endl;
    }
    
    
   
    return 0;
}
