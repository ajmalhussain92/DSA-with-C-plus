#include <iostream>
using namespace std;


string getWord (string word, int k) { 

	if (k <= 1) return "";

	int i = 0 ;
	string temp;

	while (word[i] != '\0') { 
		if (word[i] == 'z') {
			temp.append(1, 'a');
		}
		
		temp.append (1, word[i] + 1);
		i++;
		k--;
	}

	return word.append(temp);
} 


int main() {

    
    cout << getWord ("azb", 5);


	return 0;
}
