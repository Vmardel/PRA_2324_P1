#include <ostream>
#include "List.h"
#include <iostream>

template <typename T> 
class ListArray : public List<T> {

    private:
	T *arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){
			T arr2[new_size];
		for( int i = 0; i < new_size; i++){
			arr2[i] = arr[i];
		}
		delete arr;
		arr = arr2;
		max = new_size;	
	}	
        // miembros privados

    public:
	void insert(int pos, T e){
		if(pos < 0 || pos > max-1){
			throw std::out_of_range("fuera de rango");
		}
		if(n == max-1){
			resize(max + 1);
		}
		if( pos == 0){
			prepend(e);
		}
		if( pos == n){
			append(e);
		}
		for(int i = n+1; i > pos; i--){
			arr[i] = arr[i-1];
		}
		arr[pos] = e;
	}

	void append(T e){
		if (n == max) {
            		resize(max * 2);
		}
		for(int i = n; i > 0; i--){
			arr[i + 1] = arr[i];
		}
		arr[0] = e;
	}

	void prepend(T e){
		if (n == max) {
			resize(max * 2);
		}
		arr[n+1] = e;
            	
	}

	T remove(int pos){
		if(pos >= 0 && pos < size()-1){
                        return arr[pos];
			delete[] arr;
                }
                else{
                        throw std::out_of_range("fuera de rango");
                }
	}
	
	T get(int pos) const{
		if(pos >= 0 && pos < size()-1){
                        return arr[pos];
                }
                else{
                        throw std::out_of_range("fuera de rango");
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
		if(n != 0){
			return false;
		}
		return true;
	}

	int size() const{
		return n;
	}

	ListArray(){
		if( MINSIZE != 2 ){
			throw std::invalid_argument("valor erroneo en el MINSIZE" );
		}
		arr = new T[MINSIZE];
	}

	~ListArray(){
		delete arr;
	}

	T operator[](int pos){
		if( pos < 0 || pos > size()-1 ){
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
