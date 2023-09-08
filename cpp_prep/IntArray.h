#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert> // for assert()

class IntArray
{
	private:
		int m_length{};
		int* m_data{};

	public:
		IntArray() = default;

		IntArray(int length):
			m_length{ length }
		{
			assert(length >= 0);

			if (length > 0)
				m_data = new int[length]{};
		}

		~IntArray()
		{
			delete[] m_data;
			// we don't need to set the length of the object to 0, since the object would be 
			// destroyed immediately after this
		}

		void erase(){
			delete[] m_data;
			// make sure to make this null ptr otheriwse it would be pointing to deallocated memory
			m_data = nullptr;
			m_length = 0;
		}

		//we are overloading the [] operator
		//return int& and not int allows us to modify the elements of the array
		int& operator[](int index){
			assert(index>=0 && index<m_length);
			return m_data[index];
		}

		int getLength() const{
			return m_length;
		}

		void reallocate(int newlength){
			erase();
			if(newlength<=0){
				return;
			}
			m_data = new int[newlength];
			m_length = newlength;
		}

		// copy constructor is different from copy assignment operator
		// it is for purposes like
		// IntArray a;
		// IntArray b = a
		IntArray(const IntArray& a)
		{
			// Set the size of the new array appropriately
			reallocate(a.getLength());

			// Then copy the elements
			for (int index{ 0 }; index < m_length; ++index)
				m_data[index] = a.m_data[index];
		}

		//copy assignment operator is for making an existing object equal to an 
		// already existing object
		IntArray& operator=(const IntArray& a)
		{
			// Self-assignment check
			if (&a == this)
				return *this;

			// Set the size of the new array appropriately
			reallocate(a.getLength());

			// Then copy the elements
			for (int index{ 0 }; index < m_length; ++index)
				m_data[index] = a.m_data[index];

			return *this;
		}
};

#endif


//This header file can be used normally by including "IntArray.h" in the cpp file
//I have not written insertbefore and delete any index functions for this class
//they involve process like resizing when we deallocate the existing memory and create a new memory region
//in stl these things are more optimized
//even in c++ vectors, the operations like push_back are O(1) by amortized analysis 
//worst case push_back is O(N), when we deallocate the memory and copy out the content to a new region
//they have a capacity and size different terms
//up till the capacity they write at the back, after capacity they deallocate and reallocate