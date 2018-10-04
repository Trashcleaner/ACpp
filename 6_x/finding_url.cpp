#include<vector>
#include<algorithm>
#include<iostream>
#include<string>


using std::cout;
using std::endl;
using std::vector;
using std::string;


bool not_url_char(char c){
	static const string url_ch = "~;/?:@=&$-_.+!*'(),";
	return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

string::const_iterator url_beg(string::const_iterator b, string::const_iterator e){
	static const string  sep = "://";
	typedef string::const_iterator iter;
	// i marks where the separator was found
	iter i = b;
	while ((i = search(i, e, sep.begin(), sep.end())) != e) {
		// make sure the separator isn't at the beginning or end of the line
		if (i != b && i + sep.size() != e) {
		// beg marks the beginning of the protocol-name
		iter beg = i;
		while (beg != b && isalpha(beg[-1]))
			--beg;
		// is there at least one appropriate character before and after the separato
		if (beg != i && !not_url_char(i[sep.size()]))
			return beg;
		}
		// the separator we found wasn't part of a URL advance i past this separator
		i += sep.size();
	}
	return e;
}


string::const_iterator url_end(string::const_iterator b, string::const_iterator e){
	return find_if(b, e, not_url_char);
}

vector<string> find_urls(const string& str){
	vector<string> ret;
	typedef string::const_iterator iter;
	iter b = str.begin();
	iter e = str.end();
	while(b != e){
		//find letter followed by "://"
		b = url_beg(b, e);
		if( b!=e ){
			iter after = url_end(b, e);
			ret.push_back(string(b, after));
			b = after;
		}
	}
	return ret;
}



int main(){
//cout << not_url_char(' ') << "  " << not_url_char('.') << endl;
string s = "This is very long string, containing some urls, let's try: https://google.com";
vector<string> urls = find_urls(s);
for(vector<string>::const_iterator iter = urls.begin(); iter != urls.end(); iter++){
	cout << *iter << endl;
}
return 0;
}
