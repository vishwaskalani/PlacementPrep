#include <bits/stdc++.h>
using namespace std;

// If a function is virtual, all matching overrides in derived classes are implicitly virtual.
// This does not work the other way around -- 
// a virtual override in a derived class does not implicitly make the base class function virtual.

// the return type of a virtual function and its override must match

class A
{
public:
    virtual string getName() const { return "A"; }
	virtual string getConstName() const {return "A_const";}
};

class B: public A
{
public:
    // note: no virtual keyword in B, C, and D
	// will be virtaul because it is an override
    string getName() const { return "B"; }
	virtual string getConstName() {return "B_const";}
};

class C: public B
{
public:
	// will be virtual because it is an override
    string getName() const { return "C"; }
	virtual string getConstName() {return "C_const";}
};

class D: public C
{
public:
	// will be an override because it is an override
    string getName() const { return "D"; }
	virtual string getConstName() {return "D_const";}
};

class A_n{
	public:
	A_n(){
		cout<<getName()<<endl;
	}
	virtual string getName() const{
		return "A_n";
	}

};

class B_n : public A_n{
	public:

	virtual string getName() const{
		return "B_n";
	}

};

int main(){

	C c {};
    B& rBase{ c };
	std::cout << rBase.getName() << '\n';

	// therefore must remember that virtaul propogates from top to bottom that is 
	// from base to derived class
	// but not from derived to the base class
	// even changes like the const and no const in the function signature can prevent it to be override

	C c_const {};
    A& rBase_const{ c };
    std::cout << rBase_const.getConstName() << '\n';

	// seeing what happens in constructor
	B_n obj1 {};
	// the derived classes have not been constructed when the print statement is called

	return 0;
}