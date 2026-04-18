#include <iostream>
#include<string>
#include <cctype> // For toupper() and tolower()

using namespace std;
//String Lower and Upper Case 

int main() {
    
    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    
    string lowerStr = txt;
    
    // Convert to lowercase
    for(char& ch : lowerStr){
        ch = tolower(ch);
    }
    
    string upperStr = txt;
    
    // Convert to uppercase
    for(char& ch : upperStr){
        ch = toupper(ch);
    }
    
    
    
    cout<<"Original String: "<< txt <<endl;
    
    cout<<"Lower Case: "<< lowerStr <<endl;
    
    cout<<"Upper Case: "<< upperStr <<endl;
    
    
    
    
    
    return 0;
}
/*

-> toupper() and tolower() functions provided by the <cctype> library.
-> These functions work character by character.
-> For strings, you can iterate through each character and apply the transformation.

*/











