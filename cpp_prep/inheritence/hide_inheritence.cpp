#include <bits/stdc++.h>
using namespace std;

class Base
{
private:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }
	int extra_val {5}; // we can make the public members of the base class private in the inherited class

	int getValue() const { return m_value; }

protected:
    void printValue() const { std::cout << m_value<<endl; }
};

class Derived: public Base
{
private:
	using Base::extra_val;
public:
    Derived(int value)
        : Base { value }
    {
    }

    // Base::printValue was inherited as protected, so the public has no access
    // But we're changing it to public via a using declaration
    using Base::printValue; // note: no parenthesis here
	int getValue() const = delete; // mark this function as inaccessible
};

int main(){

	Derived der {7};
	der.printValue();
	//cout<<der.extra_val<<endl; //will get an error because it is private attribute now
	//but we can statically cast the derived class in the base class
	Base& base{ static_cast<Base&>(der) };
	std::cout << base.extra_val<<endl; // okay: extra_val is public in Base

	// we can delete the functions in base class in the derived class
	// cout<<der.getValue()<<endl; // can't be accessed as it is a deleted function
	Base& bas{ static_cast<Base&>(der)};
	cout<<bas.getValue()<<endl;
	return 0;
}