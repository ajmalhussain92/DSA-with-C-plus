#include<iostream>
#include<cstring>
#include<string>

//String & All its Functions and Methods

using namespace std;
int main(){
	string str1="Gabriel";
	//Accessing Characters at specified index
	//1. at(index):
	char ch1=str1.at(3);   
	cout<<ch1<<endl;       //Output: r
	//2. stringName[index]:
	char ch2=str1[3];
	cout<<ch2<<endl;       //Output: r
	
	//Length and Size
	//1. .length():
	int len1=str1.length();
	cout<<len1<<endl;
	//2. .size():
	int len2=str1.size();
	cout<<len2<<endl;
	
	//Appending and Concatenating
	//1. append():
	str1.append(" How are you? "); //Note: converts into a new string permanent
	cout<<str1<<endl;      //Output: Gabriel How are you?
	//2. operator + 
	string greeting = "Hello "+str1;
	cout<<greeting<<endl;
	
	//Comparing Strings
	int res=str1.compare("Farheen");
	cout<<res<<endl;       //Output: 1
	
	//Substrings Extract
	//substr(start,length):
	string sub=str1.substr(0,4);
	cout<<sub<<endl;       //Output: Gabr
	cout<<str1.substr(3)<<endl;   //Output: riel     (by default, length is full when not given)
	
	//Searching
	//.find():
	string str2="Hello, World";
	size_t pos = str2.find("World");
	cout<<pos<<endl;       //Output: 7  (string found at 7th index)
	
	//Modifying Strings
	//1. replace(start, length, "new_str"):
	str2.replace(0,2,"Hi");
	cout<<str2<<endl;
	//2. insert(position, "new_str"):
	string str3="AppleMango";
	str3.insert(5,"Guava");
	cout<<str3<<endl;   //Output: AppleGuavaMango
	//3. erase(start, length):
	string str4="WonderWoman";
	str4.erase(0,6);
	cout<<str4<<endl;   //Output: Woman
	
	//Conversion
	//c_str():
//	const char* cstr=str5.c_str();

	return 0;
}