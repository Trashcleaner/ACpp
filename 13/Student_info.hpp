#ifndef ACPP_GUARD_STUDENT_INFO_HPP
#define ACPP_GUARD_STUDENT_INFO_HPP

#include<iostream>
#include<string>
#include<stdexcept>

#include"Core.hpp"
#include"Grad.hpp"



class Student_info {

	public:
		Student_info() : cp(0) { }
		Student_info(std::istream& is) : cp(0) { read(is); }

		//copy constructor
		Student_info(const Student_info&);

		//asignment operator
		Student_info& operator=(const Student_info&);

		~Student_info() { delete cp; }

		//other class members
		std::string name() const{
			if(cp){
				return cp->name();
			} else{
				throw std::runtime_error("uninitialized Si");
			}
		}

		double grade() const{
			if(cp){
				return cp->grade();
			} else{
				throw std::runtime_error("uninitialized Si");
			}
		}

		std::istream& read(std::istream&);

		//static methods
		static bool compare(const Student_info& a, const Student_info& b){
			return a.name() < b.name();
		}

	private:
		Core *cp;
};

#endif
