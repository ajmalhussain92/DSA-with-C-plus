#include <iostream>
#include <cmath>
using namespace std;
//Decimal to Hexadecimal Conversion

int hexadecimalNum(int decimalNum){
	
	int hexNum = 0, remainder, pow = 1;
	
	while(decimalNum != 0){
		
		remainder = decimalNum % 16;
		
		hexNum = hexNum + remainder * pow;
		
		decimalNum /= 16;
		pow *= 10;
	}
	return hexNum;
}


int main() {
    
    int num;
    
    cout << "Enter the number: ";
    cin >> num;
    
    int res = hexadecimalNum(num);
    
    cout << "Hexadecimal number: " << res;
    
    return 0;
}
