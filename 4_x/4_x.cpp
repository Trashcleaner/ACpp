// include directives and using-declarations for library facilities
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<ios>
#include<string>
#include<stdexcept>
#include<list>

#include"grade.hpp"
#include"Student_info.hpp"

using std::list;
using std::cin;
using std::endl;
using std::vector;
using std::sort;
using std::streamsize;
using std::string;
using std::setprecision;
using std::domain_error;
using std::max;
using std::cout;


int main()
{

	//load students
	vector<Student_info> students;
	Student_info record;
	string::size_type maxLen = 0;
	while(read(cin, record)){
		maxLen = max(maxLen, record.name.size());
		students.push_back(record);
	}

	// alphabetize the records
	sort(students.begin(), students.end(), compare);

	for (vector<Student_info>::const_iterator iter = students.begin();
		iter != students.end(); iter++) {
		// write the name, padded on the right to maxlen + 1 characters
		//NOTE: we can write: 
		// (iter*).name, iter->name
		//It is equivalent
		cout << iter->name << string(maxLen + 1 - iter->name.size(), ' ');

		// compute and write the grade
		try {
			double final_grade = grade(*iter);
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
			<< setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}
