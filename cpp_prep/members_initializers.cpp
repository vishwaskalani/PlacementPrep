#include <bits/stdc++.h>
using namespace std;

// class Something
// {
// private:
//     const int m_value;

// public:
//     Something()
//     {
//         m_value = 1; // error: const vars can not be assigned to
//     }
// };


class Something
{
private:
    int m_value1 {};
    double m_value2 {};
    char m_value3 {};
	const int m_value4 {};

public:
    Something() : m_value1{ 1 }, m_value2{ 2.2 }, m_value3{ 'c' }, m_value4 { 3 } // Initialize our member variables
    {
    // No need for assignment here
    }

    void print()
    {
         std::cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 <<", "<<m_value4<<")\n";
    }
};

class A
{
public:
    A(int x = 0) { std::cout << "A " << x << '\n'; }
};

class B
{
private:
    A m_a {};
public:
    B(int y)
        : m_a{ y - 1 } // call A(int) constructor to initialize member m_a
    {
        std::cout << "B " << y << '\n';
    }
};

class Rectangle
{
private:
	//static int shapeid{2}; //static variables can't have such in class initialization, they can also not be intitialized with the intializers list
	static int shapeid;
    double m_length{ 1.0 }; // m_length has a default value of 1.0
    double m_width{ 1.0 }; // m_width has a default value of 1.0

public:
	// note: No default constructor provided in this example

    Rectangle(double length, double width)
        : m_length{ length },
          m_width{ width }
    {
        // m_length and m_width are initialized by the constructor (the default values aren't used)
    }

    void print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << '\n';
    }
};


int main(){
	Something obj1;
	obj1.print();

	//we can intialize the const members using the members intializers list and not the assignment after the initialization of the variable

	//we can also initialize class members using this sort of initialization
	B b{5};

	//Rectangle x{}; // will not compile, no default constructor exists, even though members have default initialization values

	return 0;
}