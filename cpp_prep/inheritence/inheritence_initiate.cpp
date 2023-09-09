#include <bits/stdc++.h>
using namespace std;

class Base
{
	public : 

	int m_id {};
	Base(int id=0):m_id {id} 
	{
		cout<<"Constructing base class"<<endl;
	}
	int getid(){
		return m_id;
	}
};

class Derived : public Base
{
	public :

	double m_cost {};

    Derived(double cost=0.0)
        : m_cost { cost }
    {
        cout << "Constructing derived class"<<endl;
    }

    double getCost() const { return m_cost; }
};

class A
{
public:
    A()
    {
        std::cout << "A\n";
    }
};

class B: public A
{
public:
    B()
    {
        std::cout << "B\n";
    }
};

class C: public B
{
public:
    C()
    {
        std::cout << "C\n";
    }
};

class D: public C
{
public:
    D()
    {
        std::cout << "D\n";
    }
};


int main(){

	cout<<"Let us see the order of the construction"<<endl;
	Derived der;
	cout<<endl;
	cout<<"Let us see the order in a chain"<<endl;
	D d;
	return 0;
}