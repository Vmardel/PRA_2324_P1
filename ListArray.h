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
			T *arr2= new T[new_size];
		for( int i = 0; i < max; i++){
			arr2[i] = arr[i];
		}
		delete[] arr;
		arr = arr2;
		max = new_size;	
	}	
        // miembros privados

    public:
	void insert(int pos, T e) override{
		if(pos < 0 || pos > n){
			throw std::out_of_range("fuera de rango");
		}
		if(n == max){
			resize(max * 2);
		} 
		if( pos == 0){
			prepend(e);
		}
		else if( pos == size()){
			append(e);
		}
		else { for(int i = n; i > pos; i--){
			arr[i] = arr[i-1];
		}
		arr[pos] = e;
		n++;
		}
	}

	void prepend(T e) override{
		if (n == max) {
            		resize(max * 2);
		}
		if(n!=0){
		for(int i = n; i > 0; i--){
			arr[i] = arr[i - 1];
		}
		}
		arr[0] = e;
		n++;
	}

	void append(T e) override{
		if (n == max) {
			resize(max * 2);
		}
		arr[n] = e;
            	n++;
	}

	T remove(int pos) override{
		T aux;
		if(pos >= 0 && pos < size()){
                        aux = arr[pos];
			for(int i = pos; i < n; i++){
				arr[i] = arr[i+1];
			}
		}
                else{
                        throw std::out_of_range("fuera de rango");
                }
		n--;
                return aux;
	}
	
	T get(int pos) override{
		if(pos >= 0 && pos < size()){
                        return arr[pos];
                }
                else{
                        throw std::out_of_range("fuera de rango");
                }
        }

	int search(T e) override{
		int i = 0;
		for( i; i < size(); i++){
			if( arr[i] == e){
				return i;
			}
		}
		return -1;
	}

	bool empty() override{
		if(n != 0){
			return false;
		}
		return true;
	}

	int size() override{
		return n;
	}

	ListArray(){
		arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;
	}

	~ListArray(){
		n = 0;
		delete[] arr;
	}

	T& operator[](int pos){
		if( pos < 0 || pos >= size() ){
			throw std::out_of_range("esta fuera de rango" );
		}
		else{
			return arr[pos];		
		}
	}	

	friend std::ostream& operator<<(std::ostream &out, ListArray<T> &list){
			for(int i = 0;i < list.size(); i++){
				out<<list[i]<<std::endl;
			
			} 
			return out;
	}

        // miembros públicos, incluidos los heredados de List<T>   
};
