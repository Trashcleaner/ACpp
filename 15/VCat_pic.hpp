#ifndef ACPP_GUARD_VCAT_PIC_HPP
#define ACPP_GUARD_VCAT_PIC_HPP


#include"Ptr.hpp"
#include"Pic_base.hpp"

#include<iostream>

class VCat_Pic: public Pic_base {
	friend Picture vcat(const Picture&, const Picture&);
	Ptr<Pic_base> top, bottom;
	VCat_Pic(const Ptr<Pic_base>& t, const Ptr<Pic_base>& b) : top(t), bottom(b) { }
	wd_sz width() const	{
		return std::max(top->width(), bottom->width());
	}

	ht_sz height() const {
		return top->height() + bottom->height();
	}

	void display(std::ostream&, ht_sz, bool) const;
};
#endif
