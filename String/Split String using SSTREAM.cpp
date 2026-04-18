#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main () {
	string sentence = "This is a sample sentence";
	
	stringstream ss (sentence);
	string word;
	
	while (ss >> word) {
	    cout << word << endl;
	}
	
	// Reset stringstream before second use     (important)
    ss.clear();     // clear EOF/error flags
    ss.seekg(0);    // reset position to the start
	
	vector<string> words;

	while (ss >> word) {
	    words.push_back (word);
	}
	
	
	cout << "First word: " << words.front () << endl;			// This
    cout << "Last word: " << words.back () << endl;				// sentence
	
	return 0;
}

/*

stringstream to tokenizes the string based on spaces
Must reset stringstream 'ss' before second use

'ss' is a user-defined.

*/