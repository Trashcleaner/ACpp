#ifndef STR_H_GUARD
#define STR_H_GUARD

#include"Vec.h"
#include<algorithm>
#include<cstring>
#include<iterator>
#include<iostream>


/**
Str
Implementation of string class with Vec to contain data.
*/
class Str{

	public:

		typedef Vec<char>::size_type size_type;

		/*Constructors*/
		//default: create empty string
		Str(){ }


		Str(size_type n, char c) : data(n,c){
		}

		Str(const char* c){
			std::copy(c, c + std::strlen(c), std::back_inserter(data));
		}

		template<class In>
		Str(In b, In e){
			std::copy(b, e, std::back_inserter(data));
		}

		/*Operators*/
		char& operator[](size_type i){
			return data[i];
		}

		const char& operator[](size_type i) const{
			return data[i];
		}

		//experimental conversion to double
		operator double(){
			return 42.0;
		}

		/*12-6*/
		operator bool(){
			return size() == 0 ? false : true;
		}

		size_type size() const {
			return data.size();
		}

		/*Declaration for I/O operators, they cannot be member functions, see 12.3.
		declarations are here so we can make them "friends" and grant them access to private data*/
		friend std::istream& operator>>(std::istream&, Str&);
//		friend std::ostream& operator<<(std::ostream&, const Str&);


		/*Operator += needs to be member function because
		s=s+s1 is equivalent to s+=s1 which is equivalent to s.operator+=(s1)*/
		Str& operator+=(const Str& s){
			std::copy(s.data.begin(), s.data.end(), std::back_inserter(data));
			return *this;
		}

	private:
		Vec<char> data;

};

std::ostream& operator<<(std::ostream& os, const Str& s){
	/*
	//This would work but we need access to private member "data"
	//We would need a function declaration with "friend" keywoard in the header
	for(Vec<char>::const_iterator iter = s.data.begin(); iter != s.data.end(); iter++){
		os << *iter;
	}*/
	for(Str::size_type sz = 0; sz != s.size(); sz++){
		os << s[sz];
	}
	return os;
}

std::istream& operator>>(std::istream& is, Str& s){
	s.data.clear();

	char c;
	while(is.get(c) && isspace(c));

	if(is){
		do{
			s.data.push_back(c);
		} while(is.get(c) && !isspace(c));

		if(is){
			is.unget();
		}
	}
	return is;

}

/*Operator + cannot be class member*/
Str operator+(const Str& a, const Str& b){
	Str r = a;
	r+=b;
	return r;
}

#endif
