#ifndef ACPP_GUARD_PIC_BASE_HPP
#define ACPP_GUARD_PIC_BASE_HPP

#include<iostream>
#include<vector>
#include<string>
class Picture; //forward declaration

class Pic_base{

	friend std::ostream& operator<<(std::ostream&, const Picture&);
	friend class Frame_Pic;
	friend class HCat_Pic;
	friend class VCat_Pic;
	friend class String_Pic;

	// no public interface
	typedef std::vector<std::string>::size_type ht_sz;
	typedef std::string::size_type wd_sz;

	// this class is abstract
	virtual wd_sz width() const = 0;
	virtual ht_sz height() const = 0;
	virtual void display(std::ostream&, ht_sz, bool) const = 0;

	protected:
	static void pad(std::ostream& os, wd_sz beg, wd_sz end) {
		while (beg != end) {
			os << " ";
			++beg;
		}
	}
};


#endif
