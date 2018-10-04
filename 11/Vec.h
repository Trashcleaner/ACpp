#ifndef VEC_H_GUARD
#define VEC_H_GUARD

#include<iostream>
#include<algorithm>
#include<cstddef>
#include<memory>

template<class T> class Vec {
	public:
		/*type definitions*/
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;

		/*Constructors*/
		Vec(){
			create();
		}
		explicit Vec(size_type n, const T& val = T()){
			create(n,val);
		}
		/*Copy constructor*/
		Vec(const Vec& v){
			create(v.begin(), v.end());
		}
		/*Destructor*/
		~Vec(){
			uncreate();
		}

		/*Operator overloads*/
		T& operator[](size_type i){
			return data[i];
		}
		const T& operator[](size_type i) const{
			return data[i];
		}

		//NOTE: assignment(=) is different operation than initialization
		//when we initialize the object using =, in fact we are using copy constructor
		Vec& operator=(const Vec& rhs);

		/*Other interface members*/
		size_type size() const{
			return limit-data;
		}

		iterator begin(){
			return data;
		}
		const_iterator begin() const{
			return data;
		}


		iterator end(){
			return limit;
		}
		const_iterator end() const{
			return limit;
		}

		void push_back(const T& val){
			if(avail == limit)
				grow();
			unchecked_append(val);
		}

		iterator erase(iterator it){
			if(it >= avail)
				return it;
			iterator ret = it;
			for( ; it < avail; it++){
				*it = *(it+1);
			}
			avail--;
			return ret;
		}


		iterator erase(iterator b, iterator e){
			if(b < data || e > avail)
				return b;
			iterator ret = b;
			ptrdiff_t count = e-b;
			for(; b<e; b++){
				alloc.destroy(b);
			}
			std::uninitialized_copy(e,avail,ret);
			for(iterator it = avail-count; it < avail; it++){
				alloc.destroy(it);
			}
			avail = avail - count;
			return ret;
		}

		void clear(){
//			uncreate();
			erase(data, avail);
		}

		void print_Vec(){
			const_iterator it = data;
			for( ; it != avail; it++){
				std::cout << *it << " ";
			}
			std::cout << std::endl;
		}
	private:
		iterator data;
		iterator avail;
		iterator limit;

		std::allocator<T> alloc;

		void create();
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);
		void uncreate();

		void grow();
		void unchecked_append(const T&);

};

//create
template<class T>
void Vec<T>::create(){
	data = 0;
	avail = 0;
	limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val){
	data = alloc.allocate(n);
	limit = avail = data+n;
	std::uninitialized_fill(data, limit, val);
}

template<class T>
void Vec<T>::create(const_iterator b, const_iterator e){
	data = alloc.allocate(e-b);
	limit = avail = std::uninitialized_copy(b, e, data);
}

//uncreate
template<class T>
void Vec<T>::uncreate(){
	if(data){
		iterator it = avail;
		while(it != data){
			alloc.destroy(--it);
		}
		alloc.deallocate(data, limit-data);
	}
	data = 0;
	avail = 0;
	limit = 0;
}


//operator =
template<class T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs){
	if(this != &rhs){
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

//push_back helpers
template<class T>
void Vec<T>::grow(){
	size_type new_size = std::max((limit-data)*2, ptrdiff_t(1)); //in case it's empty choose new_size 1
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, limit, new_data);
	iterator new_limit = new_data + new_size;

	uncreate();

	data = new_data;
	avail = new_avail;
	limit = new_limit;
}

template<class T>
void Vec<T>::unchecked_append(const T& val){
	alloc.construct(avail++ ,val);
}

#endif
