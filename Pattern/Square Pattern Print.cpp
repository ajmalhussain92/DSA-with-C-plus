#include<iostream>
using namespace std;
//Square Pattern

int main(){

int  n;

cout<<"Enter a num: ";
cin>>n;

cout<<"\n1234... Square Pattern\n";
for(int r=0; r<n; ++r){
    
    int num = 1;
    for(int c=0; c<n; c++){
        
        cout<<num <<" ";
        num+=1;
    }
    cout<<endl;
}

cout<<"\n1234(increasing)... Square Pattern\n";
int num = 1;
for(int r=0; r<n; ++r){
    

    for(int c=0; c<n; c++){
        
        cout<<num <<" ";
        num+=1;
    }
    cout<<endl;
}

cout<<"\n****(star)... Square Pattern\n";
for(int r=0; r<n; ++r){
    

    for(int c=0; c<n; c++){
        
        cout<<"* ";
    }
    cout<<endl;
}

cout<<"\nABCD... Square Pattern\n";
for(int r=0; r<n; ++r){
    
    char ch = 'A';
    for(int c=0; c<n; c++){
        
        cout<<ch <<" ";
        ch+=1;
    }
    cout<<endl;
}

    return 0;
}