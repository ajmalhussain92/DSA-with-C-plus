#include <iostream>
using namespace std;

int main () {
    
    /* char to int */
    
    char c = '7';
    int num = c - '0';
    cout << num << endl;
    
    // ----------------------------
    
    char c1 = '7';
    char c2 = '8';
    char c3 = '6';
    char c4 = '9';
    char c5 = '2';
    
    cout << c1 - '0' << endl;
    cout << c2 - '0' << endl;
    cout << c3 - '0' << endl;
    cout << c4 - '0' << endl;
    cout << c5 - '0' << endl;
    
    int number = (c1 - '0') * 100 + (c2 - '0') * 10 + (c3 - '0') * 1;
    cout << number << endl;
    
    
    cout << '0' + '0' << endl;      // 48 + 48
    cout << '2' + '2' << endl;      // 50 + 50		(still char type)
    
    
    // Integer Promotion
    int n = '2' + '2';				// 50 + 50		(n = int = 100 = 100)
    char m = '2' + '2';				// 50 + 50		(m = char = 100 = d)

    cout << n << endl;				// 100			(int)
    cout << m << endl;				// d			(ASCII 100 corresponds to d)
    
    
    
    cout << int (c1) << endl;       // character -> ASCII value
    cout << c1 - '0' << endl;       // ASCII - ASCII    (97 - 48)
    
    return 0;
}

/*

Reason:
char	ASCII
'0' 	48
'1' 	49
'2' 	50
'3' 	51
----------------

'0' - '0' = 48 - 48 = 0
'1' - '0' = 49 - 48 = 1
'2' - '0' = 50 - 48 = 2
'3' - '0' = 51 - 48 = 3

char, short, bool are automatically promoted to int before calculation = Integer Promotion

*/