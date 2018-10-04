#include"HCat_pic.hpp"

using std::ostream;

void HCat_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	left->display(os, row, do_pad || row < right->height());
	right->display(os, row, do_pad);
}
