#include <bits/stdc++.h>
using namespace std;

class Employee
{
private:
    int m_id{};
    std::string m_name{};

public:
    Employee(int id=0, std::string name=""):
        m_id{ id }, m_name{ name }
    {
        std::cout << "Employee " << m_name << " created.\n";
    }

    // Use a delegating constructor to minimize redundant code
    Employee(std::string name) : Employee{ 0, name }
    { 

		//u can't have a delegating constructor declared inside these braces 
		// it has to be placed in the members intializers list


	}
};

class Foo
{
private:
    const int m_value { 0 };

	void setup() // setup is private so it can only be used by our constructors
    {
        // code to do some common setup tasks (e.g. open a file or database)
        std::cout << "Setting things up...\n";
    }

public:
    Foo()
    {
         // code to do some common setup tasks (e.g. open a file or database)
		setup(); // we used this to avoid a lot of boiler plate code
    }

    Foo(int value) : m_value { value } // we must initialize m_value since it's const
    {
        // how do we get to the common initialization code in Foo()?
		setup(); // we used this to avoid a lot of boiler plate code
    }

};


// this is a way of resetting the class without having to mention the default values in the reset function
class Foo_reset
{
private:
    int m_a{ 5 };
    int m_b{ 6 };


public:
    Foo_reset()
    {
    }

    Foo_reset(int a, int b)
        : m_a{ a }, m_b{ b }
    {
    }

    void print()
    {
        std::cout << m_a << ' ' << m_b << '\n';
    }

    void reset()
    {
        // consider this a bit of magic for now
        *this = Foo_reset{}; // create new Foo object, then use assignment to overwrite our implicit object
    }
};

int main(){

	Employee emp("Vishwas");
	// this prints the line from the first constructor

	// but we can only intialize or delegate the constructor

	// resetting the class
	Foo_reset a{1,2};
	a.reset();
	a.print();
	return 0;
}