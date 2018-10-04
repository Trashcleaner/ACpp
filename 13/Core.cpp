#include"Core.hpp"
#include"grade.hpp"

using std::istream;
using std::vector;
using std::string;

using std::cout;
using std::endl;

string Core::name() const{
	return n;
}

istream& Core::read_common(istream& is){
	cout << "Enter name, midterm, finals" << endl;
	is >> n >> midterm >> finals;
	return is;
}

istream& Core::read_hws(istream& is, vector<double>& vec){
	//TODO imporve to stop reading at newline
	double d;
	if(is){
		cout << "Enter hws grades for " << n << ":" << endl;
		vec.clear();
		while(is >> d ){
			vec.push_back(d);
		}
		is.clear();
	}
	return is;

}

istream& Core::read(istream& is){
	cout << "Read function Core: " << endl;
	read_common(is);
	read_hws(is, hws);
	return is;
}

double Core::grade() const {
	return ::grade(midterm, finals, hws);
}

bool compare(const Core& a, const Core& b){
	return a.name() < b.name();
}

bool compare_Core_ptrs(const Core* a, const Core* b){
	return a->name() < b->name();
	//return compare(*a, *b);
}
