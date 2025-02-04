




//deconst
template <typename T>
Stack<T>::~Stack(){ 

	v.clear(); 

}

// copy const
template <typename T>
Stack<T>::Stack(){ 
	
		
}


template <typename T>
Stack<T>::Stack(Stack<T> && s){ 
	*this = s;
}


template <typename T>
Stack<T>::Stack(const Stack<T> & s){ 

	*this = s;

}
	


template <typename T>
Stack<T> & Stack<T>::operator=(const Stack<T> & t){ 

	v = t.v;

	return *this;
}

template <typename T>
Stack<T> & Stack<T>::operator=(Stack<T> && t){ 


	v = t.v;
	return *this;

}

template <typename T>
bool Stack<T>::empty() const{ 

	return v.empty();

}

template <typename T>
void Stack<T>::clear(){ 

	v.clear();

}

template <typename T>
void Stack<T>::push(const T& x){ 

	v.push_back(x);

}

template <typename T>
void Stack<T>::push(T&& x){ 

	v.push_back(x);

}

template <typename T>
void Stack<T>::pop(){ 

	v.pop_back();

}

template <typename T>
T& Stack<T>::top(){

	return v.back();
}

template <typename T>
const T& Stack<T>::top() const{ 

	return v.back();
}
	
template <typename T>
int Stack<T>::size() const{
	return v.size();
}

template <typename T>
void Stack<T>::print(std::ostream & os, char ofc) const{ 

for(auto itr = v.begin(); itr != v.end(); ++itr)
	os << *itr << ofc;

}

template <typename T>
std::ostream & operator<< (std::ostream& os, const Stack<T>& a){ 

	a.print(os);

	return os;

}

template <typename T>
bool operator== (const Stack<T>& x, const Stack<T>& y){ 

	return x.getVector() == y.getVector();

}

template <typename T>
bool operator!= (const Stack<T>& x, const Stack<T>& y){ 

	return !(x == y);
	
}

template <typename T>
bool operator<= (const Stack<T>& a, const Stack<T>& b){ 
	return a.getVector() <= b.getVector();
}



template <typename T>
std::vector<T> Stack<T>::getVector() const{ 

	return v;
	
}
