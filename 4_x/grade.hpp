#ifndef GUARD_grade_hpp
#define GUARD_grade_hpp

#include<vector>
#include"Student_info.hpp"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info&);
bool pgrade(const Student_info&);

#endif
