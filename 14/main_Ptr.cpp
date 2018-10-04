#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<algorithm>

#include"Ptr.hpp"
#include"Core.hpp"
#include"Grad.hpp"

using namespace std;

bool compare_Core_Ptrs(const Ptr<Core>& a, const Ptr<Core>& b){
	return a->name() < b->name();
}

int main()
{
	Ptr<Core> record;
	record = new Grad;

/*	vector< Ptr<Core> > students;
	Ptr<Core> record;
	char ch;
	string::size_type maxlen = 0;
	// read and store the data
	while (cin >> ch) {
		if (ch == 'U')
			record = new Core;
			// allocate a Core object
		else
			record = new Grad;
			// allocate a Grad object
		record->read(cin); // Ptr<T>::->, then virtual call to read
		maxlen = max(maxlen, record->name().size()); // Ptr<T>::->
		record.make_unique();
		students.push_back(record);
		cout << "Printing vec. Size of vec: " << students.size() << endl;
		for(auto it = students.begin(); it != students.end(); it++){
			cout << (*it)->name() << endl;
		}
	}
	// compare must be rewritten to work on const Ptr<Core>&
	sort(students.begin(), students.end(), compare_Core_Ptrs);
	// write the names and grades
	for (vector< Ptr<Core> >::size_type i = 0;
	i != students.size(); ++i) {
		// students[i] is a Ptr, which we dereference to call the functions
		cout << students[i]->name()
		<< string(maxlen + 1 - students[i]->name().size(), ' ');
		try {
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	// no delete statement
	}
*/
	return 0;
}
