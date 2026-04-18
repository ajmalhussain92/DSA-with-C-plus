#include <iostream>
using namespace std;

int main () {
    
    /* char to ASCII */
    
    char c = '0';
    int num = int(c);
    cout << num << endl;			// 48
    
    
    cout << int ('a') << endl; 		// 97
    cout << int ('A') << endl; 		// 65
    
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