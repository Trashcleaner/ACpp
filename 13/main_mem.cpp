#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<iomanip>

#include"Core.hpp"
#include"Grad.hpp"

using namespace std;


int main(int argc, char** argv){
	vector<Core*> students;
	// read and process Core records
	Core* record;
	char ch;
	string::size_type maxlen = 0;

	// read and store the data
	while (cin >> ch) {
		cout << "Core/Grad ?" << endl;
		if(ch == 'U'){
			record = new Core;
		} else  {
			record = new Grad;
		}
		record -> read(cin);
		maxlen = max(maxlen, record->name().size());
		students.push_back(record);
	}

	// alphabetize the student records
	sort(students.begin(), students.end(), compare_Core_ptrs);

	// write the names and grades
	for (vector<Core>::size_type i = 0; i != students.size(); ++i) {
		cout << students[i]->name()<< string(maxlen + 1 - students[i]->name().size(), ' ');
		try {
			double final_grade = students[i]->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
		delete students[i];
	}
	return 0;

}
