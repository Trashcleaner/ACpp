#include"Str.h"
#include"Str2.h"
#include<string>
#include<iostream>
#include<fstream>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;

int main(){
	/*Testing Str functionality*/
	Str str1;
	Str str2("str2");
	Str str3 = "str3";
	Str str4(4, '!');

	Str2 strr1;
	Str2 strr2("strr2");
	Str2 strr3 = "strr3";
	Str2 strr4(4, '!');

	//String as conditions
	if(str1){
		cout << "str1 not empty" << endl;
	}else{
		cout << "str1 empty" << endl;
	}

	if(strr2){
		cout << "strr2 not empty" << endl;
	}else{
		cout << "strr2 empty" << endl;
	}

	//c_str(), data(), copy()
	Str2 strr_file = "file.txt";
	cout << "c_out: " << strr_file.c_str() << endl;
	ofstream os(strr_file.c_str());
	os << "Hello file" << endl;

	strr_file.copy(strr4.begin(), 10);
	cout << strr4 << endl;

	//getline
	Str2 strr5;
	cout << "Enter a line: " << endl;
	getline(cin, strr5);
	cout << "Line was: " << strr5 << endl;
	return 0;
}
