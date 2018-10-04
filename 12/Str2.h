#ifndef STR_2_H_GUARD
#define STR_2_H_GUARD

#include<cstring>
#include<iterator>
#include<memory>
#include<algorithm>
#include<stdexcept>

#include<iostream>

/**
Str2
Implementation of string class with const char* and size_t len to contain chars.
More complete than Str.

TODO relational operators
TODO insert function
*/
class Str2 {
	public:
		typedef size_t size_type;
		typedef char* iterator;
		typedef const char* const_iterator;
		typedef char value_type;

		/*Constructors*/
		Str2(){
			create();
		}

		Str2(size_type n, char value){
			create(n, value);
		}

		Str2(const char* c){
			create(c);
		}

		/*Copy contructor*/
		Str2(const Str2& s){
			std::cout << "COPY CONSTR CALLED" << std::endl;
			create(s.begin(), s.end());
		}

		/*Destructor*/
		~Str2(){
			uncreate();
		}

		/*Operators*/
		char& operator[](size_type i){
			return chars[i];
		}
		const char& operator[](size_type i) const{
			return chars[i];
		}

		Str2& operator=(const Str2& rhs){
			std::cout << "ASSING OPERATOR CALLED" << std::endl;
			if(this != &rhs){
				uncreate();
				create(rhs.begin(), rhs.end());
			}
			return *this;
		}

		Str2& operator+=(const Str2& s){
			//note: back_inserter not working because 'chars' is not a container with push_back
			//std::copy(s.begin(), s.end(), std::back_inserter(chars));
			for(const_iterator it = s.begin(); it != s.end(); it++){
				this->push_back(*it);
	}
			return *this;
		}

		/*12-6*/
		operator bool(){
			return size() == 0 ? false : true;
		}

		/*other members*/
		iterator begin(){
			return chars;
		}
		const_iterator begin() const{
			return chars;
		}

		iterator end(){
			return chars+len;
		}
		const_iterator end() const{
			return chars+len;
		}
		size_type size() const{
			return len;
		}

		void push_back(const value_type& x){
			grow_and_append(x);
		}

		/* 12-2  */
		const char* c_str() const{
			return chars;
		}
		const char* data() const{
			return chars; //C++11: c_str and chars is the same
		}
		void copy(iterator, int) const;

		/* 12-8 */
		std::istream& getline(std::istream&, Str2&);

		friend std::istream& operator>>(std::istream&, Str2&);

	private:
		iterator chars;
		size_type len;

		std::allocator<char> alloc;

		void create();
		void create(size_type, char);
		void create(const char*);
		void create(const_iterator, const_iterator);
		void uncreate();

		void grow_and_append(const value_type&);
};

void Str2::create(){
	chars = 0;
	len = 0;
}

void Str2::create(Str2::size_type n, char value){
	chars = alloc.allocate(n);
	len = n;
	std::uninitialized_fill(chars, chars+len, value);
}

void Str2::create (const char* cp){
	len = std::strlen(cp);
	chars = alloc.allocate(len);
	std::copy(cp, cp + len, chars);
}

void Str2::create(Str2::const_iterator b, Str2::const_iterator e){
	len = e-b;
	chars = alloc.allocate(len);
	//std::uninitialized_copy(b, e, std::back_inserter(chars));
	std::uninitialized_copy(b,e, chars);
}

void Str2::uncreate(){
	if(chars){
		//alloc.destroy(
		alloc.deallocate(chars, len);
	}
	chars = 0;
	len = 0;
}


std::ostream& operator<<(std::ostream& os, const Str2& s){
	/*
	//This would work but we need access to private member "chars"
	//We would need a function declaration with "friend" keywoard in the header
	for(Vec<char>::const_iterator iter = s.chars.begin(); iter != s.chars.end(); iter++){
		os << *iter;
	}*/
	for(Str2::size_type sz = 0; sz != s.size(); sz++){
		os << s[sz];
	}
	return os;
}

std::istream& operator>>(std::istream& is, Str2& s){
	s.uncreate();
	if(is){
		char c;
		while(is.get(c) && isspace(c));

		if(is){
			do {
				s.push_back(c);
			} while(is.get(c) && !isspace(c));
			if(is) is.unget();
		}
	}
	return is;
}

Str2 operator+(Str2& a, Str2& b){
	Str2 ret = a;
	ret += b;
	return ret;
}


void Str2::grow_and_append(const Str2::value_type& val){
	size_type new_len = len+1;
	iterator new_chars = alloc.allocate(new_len);
	iterator new_space = std::uninitialized_copy(chars, chars+len, new_chars);
	alloc.construct(new_space ,val);

	uncreate();

	chars = new_chars;
	len = new_len;
}

void Str2::copy(Str2::iterator p, int n) const{
	int copy_len = std::min<int>(n, len);
	std::copy(chars, chars+copy_len, p);
}


std::istream& getline(std::istream& is, Str2& s){
	if(is){
		char c;
		while(is.get(c) && c != '\n'){
			s.push_back(c);
		}
	}
	return is;
}

#endif
