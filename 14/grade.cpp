#include<vector>
#include<stdexcept>
#include"median.hpp"

using std::vector;
using std::domain_error;

// code for grade(double, double, double) function from §4.1/52
double grade(double midterm, double fin, double hw){
	return 0.2*midterm + 0.4 * fin + 0.4 * hw;
}


// code for grade(double, double, const vector<double>&) function from §4.1.2/54
double grade(double midterm, double fin, const vector<double>& homeworks){
	if (homeworks.size() == 0){
		throw domain_error("student has done no homework");
	}
	return grade(midterm, fin, median<double>(homeworks.begin(), homeworks.end()));
}

