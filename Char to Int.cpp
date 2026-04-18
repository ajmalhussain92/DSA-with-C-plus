#include <iostream>
#include <climits>
using namespace std;

int main () {
    char x = '7';
    int digit = x - '0';        // converts '7' to 7
    cout << digit << endl;
    
    
    string str = "986";
    
    int num = str[0] - '0';
    cout << num << endl;
    
    
    int num2 = 0;
    for (int i = 0; i < str.length(); i++) {
        if (isdigit (str[i])) num2 = num2 * 10 + (str[i] - '0');
    }
    cout << num2 << endl;
    
    return 0;
}