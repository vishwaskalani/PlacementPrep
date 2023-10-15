#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>

template <typename T> 
class Array
{
private:
    int m_length{};
    T* m_data{};
public:
    Array(int length)
    {
        assert(length > 0);
        m_data = new T[length]{}; 
        m_length = length;
    }

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

	// these abive two commands are the deletion of copy operator and the copy assignment operator
	// so basically we would be having compilation error if we do the following things 
	//IntArray arr1(5);  // Create an IntArray object with length 5

    // Attempt to create a copy using the copy constructor (will fail)
    //IntArray arr2(arr1);  // Error: Call to deleted copy constructor

    // Attempt to use the copy assignment operator (will fail)
    //IntArray arr3 = arr1;  // Error: Call to deleted copy assignment operator

    ~Array()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;
        // We need to make sure we set m_data to 0 here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }

    // templated operator[] function defined below
    T& operator[](int index); // now returns a T&

    int getLength() const { return m_length; }
};

// member functions defined outside the class need their own template declaration
template <typename T>
T& Array<T>::operator[](int index) // now returns a T&
{
    assert(index >= 0 && index < m_length);
    return m_data[index];
}

#endif