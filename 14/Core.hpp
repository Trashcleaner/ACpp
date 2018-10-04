#ifndef ACCP_GUARD_CORE_HPP
#define ACCP_GUARD_CORE_HPP


#include<vector>
#include<string>
#include<iostream>

class Core{

	friend class Student_info;
//	friend class Handle<Core>; //?
	public:
		Core() : midterm(0), finals(0) { }
		Core(std::istream& is) { read(is); }
		virtual ~Core() { }

		std::string name() const;

		virtual double grade() const;
		virtual std::istream& read(std::istream&);
		virtual Core* clone() const { return new Core(*this); }

	protected:
		std::vector<double> hws;
		double midterm;
		double finals;

		std::istream& read_common(std::istream&);
		std::istream& read_hws(std::istream&, std::vector<double>&);
	private:
		std::string n;
};

bool compare(const Core&, const Core&);
bool compare_Core_ptrs(const Core*, const Core*);

#endif
