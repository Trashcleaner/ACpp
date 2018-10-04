#include<algorithm>
#include<iostream>
#include<cctype>
#include<vector>
using std::string;
using std::cout;
using std::vector;
using std::endl;

// true if the argument is whitespace, false otherwise
bool space(char c)
{
	return isspace(c);
}


// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
	return !isspace(c);
}


vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i = str.begin();
	while (i != str.end()) {
		// ignore leading blanks
		i = find_if(i, str.end(), not_space);

		// find end of next word
		iter j = find_if(i, str.end(), space);

		// copy the characters in [i, j)
		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}


bool isPalindrome(const string& s){
	return equal(s.begin(), s.end(), s.rbegin());
}



int main(){

	string s = "Hello this will be separated";
	vector<string> sp = split(s);

	string border = string(s.size(), ' ');
	cout << border << endl;

	for(vector<string>::const_iterator iter = sp.begin(); iter != sp.end(); iter++){
		cout << *iter << endl;
	}

	cout << border << endl;

	string lev = "level";
	if(isPalindrome(lev)){
		cout << lev << " is palindrome" << endl;
	}


	return 0;
}
