#include"Student_info.hpp"
#include"grade.hpp"
#include<vector>
#include<string>
#include<iostream>
#include<list>
#include<algorithm>

using std::vector;
using std::istream;
using std::list;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

// code for read_hw(istream&, vector<double>&) function from §4.1.3/57
istream& read_hw(istream& in, vector<double>& vec){
	if(in){
		vec.clear();
		double x;
		while(in >> x){
			vec.push_back(x);
		}
		in.clear();
	}
	return in;
}

istream& read(istream& in, Student_info& student){
	in >> student.name >> student.midterm >> student.fin;
	read_hw(in, student.homework);
	return in;
}


/**
Faster version because list is optimized for deleting random elements.
*/
list<Student_info> extract_fails(list<Student_info>& students){
	list<Student_info> fail;
	list<Student_info>::const_iterator iter = students.begin();
	while(iter != students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);  //.erase return iterator to an element right after the erased one
		} else {
			++iter;
		}
	}
	return fail;
}

/**
Similarly fast because of exploiting <algorithm>
*/
vector<Student_info> extract_fails(vector<Student_info>& students){
	//after stable_partition, students will be split in the vector. see 6.3.2
	vector<Student_info>::const_iterator iter = stable_partition(students.begin(), students.end(), pgrade);
	//vector<Student_info> fails(iter, students.end()); //This doesn't compile for some reason..
	
	vector<Student_info> fails;
	for(vector<Student_info>::const_iterator other = iter; other != students.end(); other++){
		fails.push_back(*other);
	}
	students.erase(iter, students.end());
	return fails;
}


/**
This version is much slower than the first two
*/
vector<Student_info> extract_fails_b(vector<Student_info>& students){
	vector<Student_info> fail;
	vector<Student_info>::const_iterator iter = students.begin();
	while(iter != students.end()){
		if(fgrade(*iter)){
			fail.push_back(*iter);
			iter = students.erase(iter);  //.erase return iterator to an element right after the erased one
		} else {
			++iter;
		}
	}
	return fail;
}
