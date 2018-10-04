#include<stdexcept>

template<class T>
class RefHandle{

	public:
		RefHandle() : p(0), refptr(new size_t(1)){ }
		RefHandle(T* p) : p(t), refptr(new size_t(1)){ }

		RefHandle(const RefHandle& h) : p(h.p), refptr(h.refptr) {
			*refptr++;
		}

		RefHandle& operator=(const RefHandle&);

		~RefHandle() {
			if(--*refptr == 0){
				delete p;
			}
		}

		//same as Handle
		operator bool() const { return p; }
		T& operator*() const;
		T* operator->() const;

	private:
		T* p;
		size_t* refptr;

};



template<class T>
RefHandle<T>& RefHandle<T>::operator=(const RefHandle<T>& rhs){
	++*rhs.refptr;

	if(--*refptr == 0){
		delete p;
		delete refptr;
	}

	p = rhs.p;
	refptr = rhs.refptr;

	return *this;
}


//same as Handle
template<class T>
T& RefHandle<T>::operator*() const{
	if(p) return *p;
	else throw std::runtime_error("Unbound RefHandle");
}

template<class T>
T* RefHandle<T>::operator->() const{
	if(p) return p;
	else throw std::runtime_error("Unbound RefHandle");
}
