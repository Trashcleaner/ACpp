#include<iostream>
#include<iomanip>
#include<stdexcept>
#include<algorithm>

#include"Handle.hpp"
#include"Core.hpp"
#include"Grad.hpp"

using namespace std;

bool compare_Core_handles(const Handle<Core>& a, const Handle<Core>& b){
	return a->name() < b->name();
}

int main()
{
	vector< Handle<Core> > students;
	Handle<Core> record;
	char ch;
	string::size_type maxlen = 0;
	// changed type
	// changed type
	// read and store the data
	while (cin >> ch) {
		if (ch == 'U')
			record = new Core;
			// allocate a Core object
		else
			record = new Grad;
			// allocate a Grad object
		record->read(cin); // Handle<T>::->, then virtual call to read
		maxlen = max(maxlen, record->name().size()); // Handle<T>::->
		students.push_back(record);
	}
	// compare must be rewritten to work on const Handle<Core>&
	sort(students.begin(), students.end(), compare_Core_handles);
	// write the names and grades
	for (vector< Handle<Core> >::size_type i = 0;
	i != students.size(); ++i) {
		// students[i] is a Handle, which we dereference to call the functions
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
	return 0;
}
