#include<iostream>
using namespace std;
//Triangle Pattern

int main(){

int  n;

cout<<"Enter a num: ";
cin>>n;


cout<<"\n****(star)... Triangle Pattern\n";
for(int r=0; r<n; ++r){
    
    for(int c=0; c<r+1; c++){
        
        cout<<"* ";
    }
    cout<<endl;
}

cout<<"\n123(increasing)... Triangle Pattern\n";
for(int i=0; i<n; i++){
        
        for(int j=0; j<i+1; j++){
            
            cout << j+1 << " ";
        }
        cout << endl;
    }

cout<<"\n123(decreasing)... Reverse Triangle Pattern\n";
for(int i=0; i<n; i++){
        
        for(int j=i+1; j>0; j--){
            
            cout << j << " ";
        }
        cout << endl;
    }

cout<<"\n123(increasing)... Floyd's Triangle Pattern\n";

int num = 1;
for(int i=0; i<n; i++){
        
    for(int j=0; j<i+1; j++){
            
        cout << num << " ";
        num++;
    }   
    cout << endl;
}

cout<<"\n123(fixed)... Triangle Pattern\n";
for(int i=0; i<n; i++){
        
        for(int j=0; j<i+1; j++){
            
            cout << i+1 << " ";
        }
        cout << endl;
    }

cout<<"\nABC(increasing)... Triangle Pattern\n";

for(int r=0; r<n; ++r){
    
    for(int c=0; c<r+1; c++){
        char ch = 'A';
    	ch = ch+c;
    	
        cout<<ch<<" ";
    }
    cout<<endl;
}

cout<<"\nABC(fixed)... Triangle Pattern\n";
for(int i=0; i<n; i++){
	
    char ch = 65 + i;
    
    for(int j=0; j<i+1; j++){
            
        cout << ch << " ";
    }
    cout << endl;
}


cout<<"\nInverted Triangle Pattern\n";
for(int r=0; r<n; ++r){
    
    // spaces
    for(int c=0; c<r; c++){
        
        cout<<" ";
    }
    // numbers
    for(int k=0; k<n-r; k++){
        
        cout<< (r+1);
            
    }
    cout<<endl;
}

cout<<"\nInverted Triangle Pattern (Character)\n";

for(int i=0; i<n; i++){
    //spaces
    for(int j=0; j<i; j++){
            
        cout << " ";
    }
    
    //character
    char ch = 65+i;
    for(int j=0; j<n-i; j++){
            
        cout << ch;   
    }
    cout << endl;
}

cout<<"\nPyramid Pattern\n";

for(int i=0; i<n; i++){
    // spaces
    for(int j=0; j<n-i-1; j++){
        
        cout<<" ";
    }
    // numbers
    for(int j=0; j<i+1; j++){
        
        cout<<j+1;
    }
    // 3rd Triangle
    for(int j=i; j>0; j--){
        
        cout << j;
    }
    cout<<endl;
}

cout<<"\nInverse Pyramid Pattern\n\n";
for(int i=0; i<n; i++){
    //space
    for(int j=0; j<i; j++){
            
        cout << " ";
    }
    //number
    for(int j=0; j<n-i; j++){
            
        cout << j+1;  
    }
    //number	(2nd half)
    for(int j=n-i-1; j>0; j--){
            
        cout << j;  
    }
    cout << endl;
}

cout<<"\nInverse Pyramid Pattern (Character)\n\n";
for(int i=0; i<n; i++){
    //space
    for(int j=0; j<i; j++){
            
        cout << " ";
    }
    //characetr
    for(int j=0; j<n-i; j++){
            
        cout << "*"; 
    }
    //characetr		(2nd half)
    for(int j=n-i-1; j>0; j--){
            
        cout << "*";   
    }
    cout << endl;
}

    return 0;
}