#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isPalindrome (string &s) {
    
    string str;
    
    for (char c : s) {
        
        if (isalnum(c))
            str += tolower(c);
    }
     
    
    int left = 0;
    int right = str.length() - 1;
    
    while (left < right) {
        
        if (str[left] != str[right]) 
            return false;
        
        left++;
        right--;
    }
    
    return true;
}

int main () {
    string s = "A man, a plan, a canal: Panama";
    
    cout << isPalindrome (s);

	return 0;
};