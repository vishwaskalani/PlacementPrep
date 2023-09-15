#include <bits/stdc++.h>
using namespace std;

// basic definition
// A virtual function is a special type of member function that, when called, 
// resolves to the most-derived version of the function 
// for the actual type of the object being referenced or pointed to.

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

class A
{
public:
    virtual string getName() const { return "A"; }
};

class B: public A
{
public:
    virtual string getName() const { return "B"; }
};

class C: public B
{
public:
    virtual string getName() const { return "C"; }
};

class D: public C
{
public:
    virtual string getName() const { return "D"; }
};

// A -> B -> C -> D


int main(){

	Derived der {};
	Base& rbas {der};
	cout<<"rbas is a "<<rbas.get_name()<<endl;

	C c {};
    A& rBase{ c };
    cout << "rBase is a " << rBase.getName() << '\n';
	
	// very important fact that virtual function does its operations as above only when we use 
	// reference or pointer to the object
	// this will not work if we do this directly on the object


	return 0;
}