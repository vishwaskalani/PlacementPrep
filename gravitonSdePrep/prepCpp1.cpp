#include <bits/stdc++.h>
using namespace std;

class Base{
	public:
		int m_public {};
		int getPublic() const { return m_public; }
		void identify() const { cout<<"I am Base\n"; }
	protected:
		int m_protected {};
	private:
		int m_private {};
};

class Derived: public Base{
	public:
		Derived(){
			m_public = 1;
			m_protected = 2;
			// m_private = 3; // not allowed
		}
};

class Pro: protected Base{
	// public -> protected
	// protected -> protected
	// private -> not accessible
};

class Pri: private Base{
	// public -> private
	// protected -> private
	// private -> not accessible
	public:
		Pri(){
			m_public = 1;
			m_protected = 2;
			// m_private = 3; // not allowed
		}
};

// we can also delete a function in the derived class
class Del: public Base{
	public:
		int getPublic() const = delete; // now this function is not accessible
};

// const key word has different meanings at different places
// 1. const before a variable means the variable is constant and cannot be changed
// 2. const after a member function means the function cannot modify any member variables of the class
// 3. const before a member function means it applies to the return type of the function

// When the member function is called with a derived class object,
// the compiler first looks to see if that member exists in the derived class.
// If not, it begins walking up the inheritance chain and checking
// whether the member has been defined in any of the parent classes.
// It uses the first one it finds.
// In other words, it uses the most-derived version of the function that it can find.
class mostDerived: public Derived{
	public:
		void identify() const { cout<<"I am mostDerived\n"; }
		void identify_with_base() const {
			Base::identify(); // calling base class function
			cout<<"I am mostDerived\n";
		}
};

// Example to understand the order of construction and destruction in inheritance chain
class A
{
public:
	A()
	{
		std::cout << "A\n";
	}
	~A()
	{
		std::cout << "~A\n";
	}
};

class B: public A
{
public:
	B()
	{
		std::cout << "B\n";
	}
	~B()
	{
		std::cout << "~B\n";
	}
};

class C: public B
{
public:
	C()
	{
		std::cout << "C\n";
	}
	~C()
	{
		std::cout << "~C\n";
	}
};

int main(){

	Base b;
	b.m_public = 1; // allowed
	// b.m_protected = 2; // not allowed
	// b.m_private = 3; // not allowed

	Derived d;
	d.m_public = 1; // allowed
	// d.m_protected = 2; // not allowed
	// d.m_private = 3; // not allowed

	Pro p;
	// p.m_public = 1; // not allowed
	// p.m_protected = 2; // not allowed
	// p.m_private = 3; // not allowed

	Pri r;
	// r.m_public = 1; // not allowed
	// r.m_protected = 2; // not allowed
	// r.m_private = 3; // not allowed

	mostDerived md;
	md.identify(); // calls mostDerived's identify
	md.identify_with_base(); // calls Base's identify and then mostDerived's identify

	// seeing the order of construction and destruction
	cout<<"Let us see the order of the construction and destruction"<<endl;
	{
		C c;
	}

	return 0;
}