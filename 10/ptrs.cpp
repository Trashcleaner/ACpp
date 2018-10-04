#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void changeMe(int &a){
	a = 42;
}

int main(int argc, char** argv){
	if(argc > 1){
		int i;
		for(i = 1; i < argc-1; i++){
			cout << argv[i] << " ";
		}
		cout << argv[i] << endl;
	}

	int a = 5;
	int* b = &a;
	int& c = a;
	*b = 6;
	cout << "a = " << a << endl;
	
	c = 7;
	cout << "a = " << &a << ", b = " << b << ", c = " << &c << endl;
	cout << "a = " << a << ", b = " << *b << ", c = " << c << endl;

	changeMe(a);
	cout << "a = " << a << ", b = " << *b << ", c = " << c << endl;

	return 0;
}
