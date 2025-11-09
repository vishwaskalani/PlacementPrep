#include <bits/stdc++.h>
using namespace std;

// Virtual function
// A virtual function is a member function in the base class that you expect to override in derived classes.

class Base{
	public:
	virtual string get_name() const{
		return "Base";
	}
};

class Derived: public Base{
	public:
	virtual string get_name() const{
		return "Derived";
	}
};

// Virtual function leads to a dynamic dispatch/ run time polymorphism
// It uses a vtable to resolve the function call at runtime
int main(){

	Derived der {};
	Base& rbas {der};
	cout<<"rbas is a "<<rbas.get_name()<<endl;
	cout<<"der is a "<<der.get_name()<<endl;	

	// NOTE: virtual functions don't work in object slicing
	Base b = der; // object slicing
	// This means that the derived part of the object is "sliced off" when it is assigned to a base class object.
	cout<<"b is a "<<b.get_name()<<endl;


	return 0;
}