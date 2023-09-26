#include <ostream>
#include "List.h"
#include <iostream>
template <typename T> 
class ListArray : public List<T> {

    private:
	T *arr;
	int max;
	int a;
	static const int MINSIZE;
	void resize(int new_size){

	}	
        // miembros privados

    public:
	virtual void insert(int pos, T e){
		if(e > 0 && e < size()){
			arr[pos] = e;
		}
		else(){
			std::cout << "fuera de rango" << std::endl;
		}
	}

	virtual void append(T e){
		arr[max] = e;
	}

	virtual void prepend(T e){
		arr[0] = e;
	}

	virtual T remove(int pos){
		if(e >= 0 && e < size()-1){
                        return arr[pos];
			delete[] arr[pos];
                }
                else(){
                        std::cout << "fuera de rango" << std::endl;
                }
	}
	virtual T get(int pos) const{
		if(e >= 0 && e < size()-1){
                        return arr[pos];
                }
                else(){
                        std::cout << "fuera de rango" << std::endl;
                }
        }

	virtual int search(T e) const{
		int i = 0;
		for( i; i < size(); i++){
			if( arr[i] == e){
				return i;
			}
		}
		return -1;
	}

	virtual bool empty() const{
		for(int i = 0; i < size(); i++){
			if( arr[i] != nullptr){
				return true;
			}
		}
		return false;
	}

	virtual int size() const{
		for(int i = 0; i < i++; i++){
			if(arr[i] == nullptr){
				return i;
			}
		}
	}

	ListArray();
	~ListArray();
	T operator[](int pos);
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
	}

	
        // miembros públicos, incluidos los heredados de List<T>
    
};
