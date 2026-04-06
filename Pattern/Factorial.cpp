#include<iostream>
using namespace std;

// Recursive
static int fact(int n){
    if(n == 0){
        return 1;
    } else {
        return (n*fact(n-1));
    }
}

int main(){
	
	int n;
	
	cout << "Enter number: ";
	cin >> n;
	
	
	int res = fact(n);
	
	cout << "Factorial of " << n << res;
	
	return 0;
}