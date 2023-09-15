#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    string m_name;
    int m_age{};

public:
    Person(string name, int age)
        : m_name{ name }, m_age{ age }
    {
    }

    const string& getName() const { return m_name; }
    int getAge() const { return m_age; }
	void printAbout(){
		cout<<"I am a person"<<endl;
	}
};

class Employee
{
private:
    string m_employer;
    double m_wage{};

public:
    Employee(string employer, double wage)
        : m_employer{ employer }, m_wage{ wage }
    {
    }

    const string& getEmployer() const { return m_employer; }
    double getWage() const { return m_wage; }
	void printAbout(){
		cout<<"I am an employee"<<endl;
	}
};

// Teacher publicly inherits Person and Employee
class Teacher : public Person, public Employee
{
private:
    int m_teachesGrade{};

public:
    Teacher(string name, int age, string employer, double wage, int teachesGrade)
        : Person{ name, age }, Employee{ employer, wage }, m_teachesGrade{ teachesGrade }
    {
    }
};

int main(){

	Teacher t{ "Mary", 45, "Boo", 14.3, 8 };
	// thus we can see that a class can have multiple parents

	// but we will have a compiler error, if we directly call a function which is present in multiple parent classes
	//t.printAbout(); // we get compiler error that this function is ambiguous
	// buw we can call it this way
	t.Person::printAbout();

	// Avoid multiple inheritance unless alternatives lead to more complexity.
	// we can have problems like diamond shaped inheritence diagram
	return 0;
}
