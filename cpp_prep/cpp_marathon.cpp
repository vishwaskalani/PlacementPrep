// this is a cpp marathon for preparation of da vinci gd
// just don't think about the results, give ur best

#include <bits/stdc++.h>
using namespace std;

class Base {
private:
    int privateMember;

protected:
    int protectedMember;

public:
    void accessMembers() {
        // Can access private and protected members within the class
        privateMember = 10;
        protectedMember = 20;
    }
	int extra_val {5};
	int get_value() const {return extra_val;}
};

class Derived : public Base {
private:
	using Base::extra_val; //this attribute has been made private even when it was public in base
public:
    void accessBaseMembers() {
        // Error: privateMember is not accessible in the derived class
		//compile error
        // privateMember = 30;

        // Can access protectedMember in the derived class
        protectedMember = 40;
    }
	int get_value() const = delete; // deleting a function in the derived class and it can no longer be accessed
};

struct Example {
    char a;    // 1 byte
    int b;     // 4 bytes (on most systems)
    double c;  // 8 bytes (on most systems)
};

struct ExamplePadded {
    char a;      // 1 byte
    char padding1; // 3 bytes of padding added by the compiler
    char padding2; 
    char padding3; 
    int b;       // 4 bytes (on most systems)
    double c;    // 8 bytes (on most systems)
};

#pragma pack(1)
struct PackedExample {
	char a;
	int b;
	double c;
};
#pragma pack()

template <typename T>
class MyVector {
private:
    T* m_data{};
    size_t m_size{};
    size_t m_capacity{};

public:
    MyVector() : m_size(0), m_capacity(10) {
        m_data = new T[m_capacity]{};
    }

    ~MyVector() {
        delete[] m_data;
    }

    void pushBack(const T& value) {
        if (m_size == m_capacity) {
            resize();
        }

        m_data[m_size++] = value;
    }

    T& operator[](size_t index) {
        assert(index < m_size);
        return m_data[index];
    }

    size_t size() const {
        return m_size;
    }

private:
    void resize() {
        m_capacity *= 2;
        T* new_data = new T[m_capacity]{};

        for (size_t i = 0; i < m_size; ++i) {
            new_data[i] = m_data[i];
        }

        delete[] m_data;
        m_data = new_data;
    }
};


int main(){
	cout<<"Size of example "<<sizeof(Example)<<endl;
	cout<<"Size of example padded "<<sizeof(ExamplePadded)<<endl;
	cout<<"Size of pragma padded "<<sizeof(PackedExample)<<endl;
	return 0;
}

// new things to cover

//command line arguments in C++
//file reading and writing in C++
//Priority of operators in C++
//shared pointer in C++
//enums in C++
