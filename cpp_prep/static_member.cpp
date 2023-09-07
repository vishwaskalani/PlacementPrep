#include <bits/stdc++.h>
using namespace std;

// static variables keep their values and are not destroyed even after they go out of scope
//basic review of static variables
int generateID()
{
    static int s_id{ 0 };
    return ++s_id;
}

//static variables of a class are shared by all the objects of that class
class Something{
	public:
		static int s_value;
};

int Something::s_value{ 1 };
// in general static variables require such a declaration outside the class
// this declaration is not required outisde class and can be done inside if it is a const int or constexpr
// it is also not required when we declare them as inline inside the class
// we can use such static variables for an identity of objects of that class
//inline allows us to change the values of such variables


class Some
{
private:
    static inline int s_idGenerator { 0 }; // C++17
//  static int s_idGenerator;              // Use this instead for C++14 or older
    int m_id { };

public:
    Some()
    : m_id { ++s_idGenerator } // grab the next value from the id generator
    {}

    int getID() const { return m_id; }
};

class Something_objless
{
public:
    static int s_value; // declares the static member variable
};

int Something_objless::s_value{ 1 };

int main(){
	cout<<generateID()<<endl;
	cout<<generateID()<<endl;
	cout<<generateID()<<endl;

	Something first;
	Something second;
	first.s_value = 2;
	cout<<first.s_value<<endl;
	cout<<second.s_value<<endl;

	//static variables are not associated with the objects
	//in fact they are associated with the class itself

	// printing the static variable independent of the object
	Something_objless::s_value = 2;
	cout<<Something::s_value<<endl;

	// Access static members by class name (using the scope resolution operator)
	//rather than through an object of the class (using the member selection operator).

	Some obj1;
    Some obj2;
    Some obj3;

    std::cout << obj1.getID() << '\n';
    std::cout << obj2.getID() << '\n';
    std::cout << obj3.getID() << '\n';

	return 0;
}