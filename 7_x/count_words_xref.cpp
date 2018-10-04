#include<iostream>
#include<string>
#include<map>
#include<cctype>
#include<vector>
#include<algorithm>
#include<ios>
#include<iomanip>

using std::vector;
using std::map;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::istream;

bool space(const char c){
	return isspace(c);
}

bool not_space(const char c){
	return !isspace(c);
}

vector<string> split(const string& s){
	vector<string> ret;
	typedef string::const_iterator iter;
	iter  b = s.begin();
	iter e = s.end();
	while(b != e){
		b = find_if(b, e, not_space);
		iter after = find_if(b, e, space);
		if(b != e){
			ret.push_back(string(b, after));
		}
		b = after;
	}
	return ret;
}

/*vector<string> split(const string& str)
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
}*/


map<string, vector<int> > xref(istream& in,
		vector<string> find_words(const string& s) = split)
{
	string line;
	int line_num = 0;
	map<string, vector<int> > ret;
	while(getline(in, line)){
		line_num++;
		vector<string> words = find_words(line);
		for(vector<string>::const_iterator iter = words.begin(); iter!=words.end(); iter++){
			ret[*iter].push_back(line_num);
		}
	}
	return ret;
}


int main()
{
	// call xref using split by default
	map<string, vector<int> > ret = xref(cin);
	// write the results
	for (map<string, vector<int> >::const_iterator it = ret.begin();
	it != ret.end(); ++it) {
		// write the word
		cout << it->first << " occurs on line(s): ";
		// followed by one or more line numbers
		vector<int>::const_iterator line_it = it->second.begin();
		cout << *line_it; // write the first line number
		++line_it;
		// write the rest of the line numbers, if any
		while (line_it != it->second.end()) {
			cout << ", " << *line_it;
			++line_it;
		}
	// write a new line to separate each word from the next
	cout << endl;
	}
	return 0;
}
