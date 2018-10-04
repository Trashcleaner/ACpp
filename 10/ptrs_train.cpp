#include<iostream>
#include<vector>


using std::cout;
using std::endl;
using std::vector;

int main(int argc, char **argv){
	if(argc > 1){
		for(int i = 1; i<=argc; i++){
			cout<< argv[i] << endl;
		}
	}

	//just something that came to my mind to try out
	const vector<int> vec(10, 1);
	//vec.push_back(1);
	//vec.push_back(2);
	const int& cp = vec[0];
	//cp = 4;
	cout << vec[0] << endl;
	return 0;
}
