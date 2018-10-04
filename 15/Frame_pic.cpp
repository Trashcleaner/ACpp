#include"Frame_pic.hpp"
using std::ostream;
using std::string;

void Frame_Pic::display(ostream& os, ht_sz row, bool do_pad) const
{
	if (row >= height()) {
		// out of range
		if (do_pad)
			pad(os, 0, width());
	} else {
		if (row == 0 || row == height() - 1) {
		// top or bottom row
		os << string(width(), '*');
		} else if (row == 1 || row == height() - 2) {
			// second from top or bottom row
			os << "*";
			pad(os, 1, width() - 1);
			os << "*";
		} else {
			// interior row
			os << "* ";
			p->display(os, row - 2, true);
			os << " *";
		}
	}
}
