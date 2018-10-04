#ifndef GUARD_median_h
#define GUARD_median_h

#include<vector>
#include<stdexcept>
#include<algorithm>

template<class T, class Iterator>
T median(Iterator b, Iterator e){
	if(b == e){
		throw std::domain_error("Empty");
	}
	std::vector<T> temp;
	for(Iterator it = b; it != e; it++){
		temp.push_back(*it);
	}
	sort(temp.begin(), temp.end());
	typedef typename std::vector<T>::size_type Size;
	Size size = temp.size();
	Size mid = size/2;
	return (size%2 == 0) ? (temp[mid]+temp[mid-1])/2 : temp[mid];
}

#endif
