#include <bits/stdc++.h>
using namespace std;

template<typename T, size_t N>
class ArrayStatic{

	private:
		T m_array[N]; // array of N elements of type T
		size_t m_size; // current number of elements in the array
	public:

		ArrayStatic():m_size{0}{} // default constructor initializes size to 0

		void push_back(const T& value){
			if(m_size < N){
				m_array[m_size++] = value; // add value and increment size
			}else{
				throw out_of_range("ArrayStatic is full");
			}
		}

		void pop_back(){
			if(m_size > 0){
				--m_size; // just decrement size, no need to actually remove the element
			}else{
				throw out_of_range("ArrayStatic is empty");
			}
		}

		// accessing any element
		// this is example of operator overloading
		T& operator[](size_t index){
			if(index >= m_size){
				throw out_of_range("Index out of range");
			}
			return m_array[index];
		}

		size_t size() const{
			return m_size;
		}

		size_t capacity() const{
			return N;
		}

		void clear(){
			m_size = 0; // just reset size to 0
		}
};


template<typename T>
class ArrayDynamic{

	private:
		T* m_array; // pointer to dynamic array
		size_t m_size; // current number of elements
		size_t m_capacity; // current capacity of the array

		void resize(){
			m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2; // double the capacity
			T* new_array = new T[m_capacity]; // allocate new array
			for(size_t i = 0; i < m_size; ++i){
				new_array[i] = m_array[i]; // copy old elements
			}
			delete[] m_array; // free old array
			m_array = new_array; // point to new array
		}

	public:

		ArrayDynamic():m_array{nullptr}, m_size{0}, m_capacity{0}{} // default constructor

		~ArrayDynamic(){
			delete[] m_array; // destructor to free memory
		}

		void push_back(const T& value){
			if(m_size == m_capacity){
				resize(); // resize if needed
			}
			m_array[m_size++] = value; // add value and increment size
		}

		void pop_back(){
			if(m_size > 0){
				--m_size; // just decrement size
			}else{
				throw out_of_range("ArrayDynamic is empty");
			}
		}

		T& operator[](size_t index){
			if(index >= m_size){
				throw out_of_range("Index out of range");
			}
			return m_array[index];
		}

		size_t size() const{
			return m_size;
		}

		size_t capacity() const{
			return m_capacity;
		}

		void clear(){
			m_size = 0; // reset size to 0
		}


};


int main(){

	// Testing ArrayStatic
	ArrayStatic<int, 5> staticArray;
	staticArray.push_back(1);
	staticArray.push_back(2);
	staticArray.push_back(3);
	for(size_t i = 0; i < staticArray.size(); ++i){
		cout << staticArray[i] << " "; // should print 1 2 3
	}
	cout << endl;
	staticArray.pop_back();
	staticArray.push_back(4);
	for(size_t i = 0; i < staticArray.size(); ++i){
		cout << staticArray[i] << " "; // should print 1 2 4
	}
	cout << endl;

	// Testing ArrayDynamic
	ArrayDynamic<int> dynamicArray;
	dynamicArray.push_back(10);
	dynamicArray.push_back(20);
	dynamicArray.push_back(30);
	for(size_t i = 0; i < dynamicArray.size(); ++i){
		cout << dynamicArray[i] << " "; // should print 10 20 30
	}
	cout << endl;
	dynamicArray.pop_back();
	dynamicArray.push_back(40);
	for(size_t i = 0; i < dynamicArray.size(); ++i){
		cout << dynamicArray[i] << " "; // should print 10 20 40
	}
	cout << endl;

	return 0;
}