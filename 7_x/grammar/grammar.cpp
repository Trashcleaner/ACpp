// include directives and using-declarations for library facilities
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<ios>
#include<string>
#include<stdexcept>
#include<cctype>  //func for manipulating char data
#include<numeric> //func "accumulate"
#include<iterator> //iterator adaptors, e.g. back_insertar
#include<map>
#include<cstdlib>

#include"split.hpp"

using std::cin;
using std::endl;
using std::vector;
using std::sort;
using std::streamsize;
using std::string;
using std::setprecision;
using std::domain_error;
using std::logic_error;

using std::max;
using std::cout;
using std::istream;
using std::map;

typedef vector<string> Rule;
typedef vector<Rule> Rule_Collection;
typedef map<string, Rule_Collection> Grammar;

Grammar read_grammar(istream& in){
	Grammar ret;
	string line;
	while(getline(in, line)) {
		vector<string> words = split(line);
		if(!words.empty()){
			ret[words[0]].push_back(Rule(words.begin()+1, words.end()));
		}
	}

	return ret;
}

bool is_bracketed(const string& s){
	return s.size()>1 && s[0] == '<' && s[s.size()-1] == '>';
}

int nrand(int n){
	if (n <= 0 || n > RAND_MAX)
		throw domain_error("Argument to nrand is out of range");

	const int bucket_size = RAND_MAX / n;
	int r;

	do r = rand() / bucket_size;
	while (r >= n);

	return r;
}


void gen_aux_sentence(const Grammar& grammar, const string& word, vector<string>& ret){
	if(!is_bracketed(word)){
		ret.push_back(word);
	} else {
		Grammar::const_iterator iter = grammar.find(word);
		if(iter == grammar.end()) {
			throw logic_error("empty rule");
		}
		const Rule_Collection& rule_col = iter->second;
		const Rule rule = rule_col[nrand(rule_col.size())];

		//recursively expand the selected rule
		for(Rule::const_iterator it = rule.begin(); it!=rule.end(); it++){
			gen_aux_sentence(grammar, *it, ret);
		}
	}
}


vector<string> gen_sentence(const Grammar& grammar){
	vector<string> ret;
	gen_aux_sentence(grammar, "<sentence>", ret);
	return ret;
}


int main(){
	Grammar grammar = read_grammar(cin);
	vector<string> sentence = gen_sentence(grammar);

	vector<string>::const_iterator it = sentence.begin();
	if (!sentence.empty()) {
		cout << *it;
		++it;
	}

	// write the rest of the words, each preceded by a space
	while (it != sentence.end()) {
		cout << " " << *it;
		++it;
	}
	cout << endl;

	return 0;
}


