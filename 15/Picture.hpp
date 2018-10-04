#ifndef ACPP_GUARD_PICTURE_HPP
#define ACPP_GUARD_PICTURE_HPP

#include"Ptr.hpp"
#include"Pic_base.hpp"
#include"Frame_pic.hpp"
#include"VCat_pic.hpp"
#include"HCat_pic.hpp"

#include<vector>
#include<string>

class Picture{
	friend std::ostream& operator<<(std::ostream&, const Picture&);
	friend Picture frame(const Picture&);
	friend Picture hcat(const Picture&, const Picture&);
	friend Picture vcat(const Picture&, const Picture&);

	public:
		Picture(const std::vector<std::string>& =std::vector<std::string>());
	private:
		Picture(Pic_base* ptr): p(ptr) { }
		Ptr<Pic_base> p;

};

Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);

#endif
