#include<iostream>
#include<string>
#include<iterator>

#include"split.hpp"

using std::string;
using std::cin;
using std::cout;
using std::ostream_iterator;


int main(){

	string line;
	while(getline(cin, line)){
		split(line, ostream_iterator<string>(cout, "\n"));
	}
	return 0;

}
