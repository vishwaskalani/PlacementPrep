#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    int m_id {};

    Base(int id=0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
};

//how do we instantiate base class variables here
// we can't do it simply in the initializer's list
// because const members can't be changed in the derived class's constructor
// nor we must do the assignment in the constructor of the derived class
class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0,int id=0)
		:Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};

// similar functioning in chains of inheritence
class A
{
public:
    A(int a)
    {
        std::cout << "A: " << a << '\n';
    }
	~A(){
		cout<<"Deleting A"<<endl;
	}
};

class B: public A
{
public:
    B(int a, double b)
    : A{ a }
    {
        std::cout << "B: " << b << '\n';
    }
	~B(){
		cout<<"Deleting B"<<endl;
	}
};

class C: public B
{
public:
    C(int a, double b, char c)
    : B{ a, b }
    {
        std::cout << "C: " << c << '\n';
    }
	~C(){
		cout<<"Deleting C"<<endl;
	}
};



int main(){

	Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    cout << "Id: " << derived.getId() << '\n';
    cout << "Cost: " << derived.getCost() << '\n';

	C c{ 5, 4.3, 'R' };

	//When a derived class is destroyed, each destructor is called in the reverse order of construction. 
	// you can see that in the print order
	return 0;
}