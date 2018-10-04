// include directives and using-declarations for library facilities
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stdexcept>
#include<cctype>  //func for manipulating char data
#include<numeric> //func "accumulate"
#include<iterator>

using std::cin;
using std::endl;
using std::vector;
using std::sort;
using std::string;
using std::cout;

void some_example_hcat(vector<string>& bottom, vector<string>& top){

	//for (vector<string>::const_iterator it = bottom.begin();
	//it != bottom.end(); ++it)
	//	ret.push_back(*it);
	copy(bottom.begin(), bottom.end(), back_inserter(top));
	return;
}

int main(){
	vector<string> bot = {"Hello", " bottom"};
	vector<string> top = {"Hello", "top"};

	cout << bot.size() << " " << top.size() << endl;

	some_example_hcat(bot, top);
	for(vector<string>::const_iterator iter = top.begin(); iter != top.end(); iter++){
		cout << *iter << endl;
	}

	cout << bot.size() << " " << top.size() << endl;

	return 0;
}
