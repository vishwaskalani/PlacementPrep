#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    virtual ~Base() // note: not virtual
    {
        cout << "Calling ~Base()\n";
    }
};

class Derived: public Base
{
private:
    int* m_array {};

public:
    Derived(int length)
      : m_array{ new int[length] }
    {
    }

    virtual ~Derived() // note: not virtual (your compiler may warn you about this)
    {
        cout << "Calling ~Derived()\n";
        delete[] m_array;
    }
};

int main(){
	
	Derived* derived { new Derived(5) };
    Base* base { derived };
	// without declaring destructor as virtual, it will only call the base destructor
    delete base;
	// after declaring the desrtuctor as virtual, it will call the destructors of the base and the derived class
	// in fact you only need to mention the base class destructor as virtual, the other one would be overriden

	return 0;
}