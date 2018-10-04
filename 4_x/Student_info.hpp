#ifndef GUARD_Student_info_hpp
#define GUARD_Student_info_hpp

#include<vector>
#include<iostream>
#include<string>
#include<list>

struct Student_info{
	std::string name;
	double midterm, fin;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

// code for read_hw(istream&, vector<double>&) function from §4.1.3/57
std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read(std::istream&, Student_info&);


//returns list with fail. Vector version
std::vector<Student_info> extract_fails(std::vector<Student_info>&);

//returns list with fails. list version because of fast remove time
std::list<Student_info> extract_fails(std::list<Student_info>&);

//easier version but slower
std::vector<Student_info> extract_fails_b(std::vector<Student_info>&);
#endif
