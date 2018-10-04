#ifndef GUARD_generic_split_hpp
#define GUARD_generic_split_hpp

#include<string>
#include<algorithm>


bool space(char);
bool not_space(char);

template <class Out>
void split(const std::string& s, Out os){
	typedef std::string::const_iterator iter;

	iter b = s.begin();
	iter e = s.end();

	while(b != e){
		b = find_if(b, e, not_space);
		iter after = find_if(b, e, space);
		if(b != e){
			*os++ = std::string(b, after);
		}
		b = after;
	}
}


#endif
