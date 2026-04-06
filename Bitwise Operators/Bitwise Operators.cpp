#include <iostream>
#include<typeinfo>
using namespace std;
//Bitwise Operators

int main() {
    
    //Bitwise & (AND)
    cout << (4 & 8) << endl;        //output: 0
    
    
    //Bitwise | (OR)
    cout << (4 | 8) << endl;        //output: 12
    
    
    //Bitwise ^ (XOR)
    cout << (4 ^ 8) << endl;        //output: 12
    
    cout << (7 ^ 4) << endl;        //output: 3
    
    cout << (5 ^ 5) << endl;		//output: 0		(Note:- XOR of two same value is always zero.)
    cout << (5 ^ 5) << endl;		//output: 0
    cout << (3 ^ 3) << endl;		//output: 0
    
    
    //Bitwise << 	(Left shift)
    int n=4, i=1;
    cout << (n<<i) << endl;			//output: 8
    
    //Bitwise >> 	(Right shift)
    cout << (n>>i) << endl;			//output: 2


	( n > i)?  cout<<"N is greater": cout<<"N is smaller";
    
    return 0;
}


