#include <bits/stdc++.h>
using namespace std;

class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value { value }
    {
    }

    void identify() const { std::cout << "I am a Base\n"; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base { value }
    {
    }
	void identify() const { std::cout << "I am a Derived\n"; }
	void identify_with_base() const 
	{
		Base::identify();
		cout<<"I am Derived \n";
	}
};

int main(){

	// When a member function is called with a derived class object, 
	// the compiler first looks to see if that member exists in the derived class. 
	// If not, it begins walking up the inheritance chain and checking 
	// whether the member has been defined in any of the parent classes. 
	// It uses the first one it finds.
	// In other words, it uses the most-derived version of the function that it can find.
	Derived der {5};
	der.identify();
	der.identify_with_base();

	// Note that when you redefine a function in the derived class, 
	// the derived function does not inherit the access specifier of the function with the same name in the base class. 
	// It uses whatever access specifier it is defined under in the derived class.

	return 0;
}