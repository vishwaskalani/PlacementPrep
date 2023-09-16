#include <bits/stdc++.h>
using namespace std;

// C++ allows you to create a special kind of virtual function called a pure virtual function 
// (or abstract function) that has no body at all! 

// A pure virtual function simply acts as a placeholder that is meant to be redefined by derived classes.

// if we have a pure virtual function in any class, that means it will be an abstract base class
// an abstract base class can't be instantiated

class Animal // This Animal is an abstract base class
{
protected:
    string m_name {};

public:
    Animal(string name)
        : m_name{ name }
    {
    }

    const string& getName() const { return m_name; }
    virtual string speak() const = 0; // note that speak is now a pure virtual function

    virtual ~Animal() = default;
};

class Cow: public Animal
{
public:
    Cow(string name)
        : Animal(name)
    {
    }

	string speak() const override { return "Moo"; } // if this was an empty function as well, this class would also become abstract base class
	// but right now it overrides the above virtual function
};

int main(){
	// Animal an{"Laila"}; // won't compile because this is an abstract base class
	Cow petcow{"Laila"};
	cout<<petcow.speak()<<endl;

	//Any class with pure virtual functions should also have a virtual destructor
	return 0;
}