#include"Vec.h"
#include<iostream>

using std::cout;
using std::endl;


int main(){
	Vec<int> my_vec;
	my_vec.push_back(1);
	my_vec.push_back(2);
	my_vec.push_back(3);
	my_vec.push_back(4);
	my_vec.print_Vec();

	my_vec.erase(my_vec.begin(), my_vec.begin()+2);
	my_vec.print_Vec();
	my_vec.clear();
	my_vec.push_back(42);
	my_vec.print_Vec();
	return 0;
}
