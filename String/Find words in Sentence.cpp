#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


int main () {
    string sentence = "In a village nestled between the mountains and the sea, there was a small, peaceful village where everyone knew each other, and the villagers often gathered at the village square to share stories, celebrate festivals, and enjoy the simple pleasures of life.";
    
    vector<string> found;
    
    string key;
    cout << "Enter the word to find: ";
    cin >> key;
    
    stringstream ss (sentence);
	string word;
	
	while (ss >> word) {
	    if (word == key) {
	        found.push_back (word);
	    }
	}
	
	for (string s : found) cout << s << " ";
	
	
	size_t pos = sentence.find (key);
	
    if (pos != string::npos) 
        cout << "\nFirst occurence index: " << pos + 1 << endl;
    else
        cout << "\nWord not found!" << endl;

	return 0;
}

/*

while (pos != string::npos) {
	cout << "Found at index: " << pos << endl;
	pos = sentence.find(key, pos + 1);  // move forward
}

*/