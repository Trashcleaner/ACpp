#include "Student_info.hpp"

using std::istream;
using std::cout;
using std::endl;

istream& Student_info::read(istream& is){
	delete cp;

	char ch;
	cout << "U = Core; Else = Grad" << endl;
	is >> ch;
	if(ch == 'U'){
		cp = new Core(is);
	} else {
		cp = new Grad(is);
	}
//	is.clear();
	return is;
}

Student_info::Student_info(const Student_info& s) : cp(0){
	if(s.cp) cp = s.cp->clone();
}

Student_info& Student_info::operator=(const Student_info& rhs){
	if(this != &rhs){
		delete cp;
		if(rhs.cp) {
			cp = rhs.cp->clone();
		} else {
			cp = 0;
		}
	}
	return *this;
}


