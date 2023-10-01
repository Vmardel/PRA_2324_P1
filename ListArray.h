#include <ostream>
#include "List.h"
#include <iostream>

template <typename T> 
class ListArray : public List<T> {

    private:
	T *arr;
	int max;
	int a;
	static const int MINSIZE = 2;
	void resize(int new_size){
		T arr2[new_size];
		for( int i = 0; i < new_size; i++){
			arr2[i] = arr[i];
		}
		delete arr;
		arr -> arr2;
		max = new_size;	
	}	
        // miembros privados

    public:
	void insert(int pos, T e){
		if(e > 0 && e < size()){
			arr[pos] = e;
		}
		else{
			std::cout << "fuera de rango" << std::endl;
		}
	}

	void append(T e){
		arr[max] = e;
	}

	void prepend(T e){
		arr[0] = e;
	}

	T remove(int pos){
		if(pos >= 0 && pos < size()-1){
                        return arr[pos];
			delete[] arr[pos];
                }
                else{
                        std::cout << "fuera de rango" << std::endl;
                }
	}
	
	T get(int pos) const{
		if(pos >= 0 && pos < size()-1){
                        return arr[pos];
                }
                else{
                        std::cout << "fuera de rango" << std::endl;
                }
        }

	int search(T e) const{
		int i = 0;
		for( i; i < size(); i++){
			if( arr[i] == e){
				return i;
			}
		}
		return -1;
	}

	bool empty() const{
		for(int i = 0; i < size(); i++){
			if( arr[i] != nullptr){
				return true;
				break;
			}
		}
		return false;
	}

	int size() const{
		for(int i = 0; i < i++; i++){
			if(arr[i] == nullptr){
				return i;
			}
		}
	}

	ListArray(){
		if( MINSIZE != 2 ){
			throw std::invalid_argument("valor erroneo en el MINSIZE" );
		}
		*arr = new T[MINSIZE];
	}

	~ListArray(){
		delete[] *arr;
	}

	T operator[](int pos){
		if( pos < 0 || pos > size-1 ){
			throw std::out_of_range("esta fuera de rango" );
		}
		else{
			return arr[pos];		
		}
	}	

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			out << ListArray();
			return out;
	}

        // miembros públicos, incluidos los heredados de List<T>   
};
