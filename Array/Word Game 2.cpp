#include <iostream>
using namespace std;


void getWord (int k, string word) {
 	if (k <= 1) return;

 	int i = 0;
 	string temp;

 	while (word[i] != '\0') {
 		temp.append (1, word[i] + 1);
 		i++;
 		k--;
 	}
 	
 	word.append (temp);
 	getWord (k, word);
}

char kthCharacter(int k, string word) {
 	getWord (k, word);
// 	cout << word;
 	return word[k-1];
} 



int main() {


 	cout << kthCharacter(5, "ab");

    
//    cout << getWord ("ab", 5);


	return 0;
}
