#ifndef ACPP_GUARD_STRING_PIC_HPP
#define ACPP_GUARD_STRING_PIC_HPP


#include"Ptr.hpp"
#include"Pic_base.hpp"

#include<iostream>
#include<string>
#include<vector>

class String_Pic : public Pic_base{
	friend class Picture;

	std::vector<std::string> data;
	String_Pic(const std::vector<std::string>& v): data(v) { }
	wd_sz width() const;
	ht_sz height() const;
	void display(std::ostream&, ht_sz, bool) const;
};

#endif
