#include <bits/stdc++.h>
using namespace std;

class Base
{
protected:
    int m_value {};

public:
    Base(int value)
        : m_value{ value }
    {
    }

    string getName() const { return "Base"; }
    int getValue() const { return m_value; }
};

class Derived: public Base
{
public:
    Derived(int value)
        : Base{ value }
    {
    }

    string getName() const { return "Derived"; }
    int getValueDoubled() const { return m_value * 2; }
};

class Animal
{
protected:
    std::string m_name;

    // We're making this constructor protected because
    // we don't want people creating Animal objects directly,
    // but we still want derived classes to be able to use it.
    Animal(string name)
        : m_name{ name }
    {
    }

    // To prevent slicing (covered later)
    Animal(const Animal&) = default;
    Animal& operator=(const Animal&) = default;

public:
    string getName() const { return m_name; }
    string speak() const { return "???"; }
};

class Cat: public Animal
{
public:
    Cat(string name)
        : Animal{ name }
    {
    }

    string speak() const { return "Meow"; }
};

class Dog: public Animal
{
public:
    Dog(string name)
        : Animal{ name }
    {
    }

    string speak() const { return "Woof"; }
};


int main(){

	Derived der{5};
	cout<<"der is a "<<der.getName()<<" and has value "<<der.getValue()<<endl;
	// an object refering to the orginal object
	Derived& rder{der};
	cout<<"rder is a "<<rder.getName()<<" and has value "<<rder.getValue()<<endl;
	// pointer to the original object
	Derived* pder{&der};
	cout<<"pder is a "<<pder->getName()<<" and has value "<<pder->getValue()<<endl;

	// Base pointer or reference to a derived object
	Base& rbas{der};
	cout<<"rbas is a "<<rbas.getName()<<" and has value "<<rbas.getValue()<<endl;
	Base* pbas{&der};
	cout<<"rbas is a "<<pbas->getName()<<" and has value "<<pbas->getValue()<<endl;

	const Cat cat{ "Fred" };
    std::cout << "cat is named " << cat.getName() << ", and it says " << cat.speak() << '\n';

    const Dog dog{ "Garbo" };
    std::cout << "dog is named " << dog.getName() << ", and it says " << dog.speak() << '\n';

    const Animal* pAnimal{ &cat };
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';

    pAnimal = &dog;
    std::cout << "pAnimal is named " << pAnimal->getName() << ", and it says " << pAnimal->speak() << '\n';


	//If only there was some way to make those base pointers call the derived version of a function instead of the base version
	// and here we land in the world of virtual functions
}