#include"Grad.hpp"

#include<algorithm>
#include<string>
using std::vector;
using std::istream;
using std::min;
using std::cout;
using std::endl;


istream& Grad::read(istream& is){
	read_common(is);
	cout << "Enter thesis grade:" << endl;
	is >> thesis;
	Core::read_hws(is, hws);
	return is;
}

double Grad::grade() const{
	return min(thesis, Core::grade());
}
