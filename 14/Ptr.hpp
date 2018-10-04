#ifndef ACPP_GUARD_PTR_HPP
#define ACPP_GUARD_PTR_HPP

#include<cstring>
#include<stdexcept>

#include<iostream>

template<class T>
class Ptr{

	public:
		//Only difference from RefHandle
		void make_unique(){
			if(*refptr != 1){
				*refptr--;
				refptr = new size_t(1);
				p = p ? p->clone() : 0;
			}
		}

		//The rest is the same
		Ptr() : p(0), refptr(new size_t(1)){
			std::cout << "First constructor of Ptr called." << std::endl;
		 }
		Ptr(T* t) : p(t), refptr(new size_t(1)){
			std::cout << "Second constructor of Ptr called." << std::endl;
		 }

		Ptr(const Ptr& h) : p(h.p), refptr(h.refptr) {
			std::cout << "Copy constructor of Ptr called." << std::endl;
			*refptr++;
		}

		Ptr& operator=(const Ptr& rhs){

			std::cout << "Assignment operator of Ptr called." << std::endl;
			++*rhs.refptr;
			if(--*refptr == 0){
				delete p;
				delete refptr;
			}
			p = rhs.p;
			refptr = rhs.refptr;
			std::cout << "refptr:" << *refptr << std::endl;
			return *this;
		}

		~Ptr() {
			std::cout << "Destructor Ptr" << std::endl;
			if(--*refptr == 0){
				std::cout << " --- deleting" << std::endl;
				delete p;
				delete refptr;
			}
		}

		//same as Handle
		operator bool() const { return p; }

		T& operator*() const {
			if(p) return *p;
			else throw std::runtime_error("Unbound Ptr");
		}

		T* operator->() const {
			if(p) return p;
			else throw std::runtime_error("Unbound Ptr");
		}

	private:
		T* p;
		size_t* refptr;

};



#endif
