#ifndef ACPP_GUARD_HCAT_PIC_HPP
#define ACPP_GUARD_HCAT_PIC_HPP


#include"Ptr.hpp"
#include"Pic_base.hpp"

#include<iostream>


class HCat_Pic: public Pic_base {
	friend Picture hcat(const Picture&, const Picture&);Ptr<Pic_base> left, right;
	HCat_Pic(const Ptr<Pic_base>& l, const Ptr<Pic_base>& r) : left(l), right(r) { }
	wd_sz width() const {
		return left->width() + right->width();
	}
	ht_sz height() const {
		return std::max(left->height(), right->height());
	 }
	void display(std::ostream&, ht_sz, bool) const;
};
#endif
