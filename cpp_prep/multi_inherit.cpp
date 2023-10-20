#include<iostream>
using namespace std;
 
class A
{
public:
  A()  { cout << "A's constructor called" << endl; }
};
 
class B
{
public:
  B()  { cout << "B's constructor called" << endl; }
};
 
class C: public B, public A  // Note the order
	// the order is based on the order of declaration of inheritence
{
public:
  C()  { cout << "C's constructor called" << endl; }
};

class Person {
public:
	Person(int x) { cout << "Person::Person(int ) called" << endl; }
	Person()     { cout << "Person::Person() called" << endl;   }
};

// without virtual there would be two copies of person class
// class Faculty : public Person {
// public:
// 	Faculty(int x):Person(x) {
// 	cout<<"Faculty::Faculty(int ) called"<< endl;
// 	}
// };

class Faculty : virtual public Person {
public:
	Faculty(int x):Person(x) {
	cout<<"Faculty::Faculty(int ) called"<< endl;
	}
};

// class Student : public Person {
// public:
// 	Student(int x):Person(x) {
// 		cout<<"Student::Student(int ) called"<< endl;
// 	}
// };

class Student : virtual public Person {
public:
	Student(int x):Person(x) {
		cout<<"Student::Student(int ) called"<< endl;
	}
};

class TA : public Faculty, public Student {
public:
	// TA(int x):Student(x), Faculty(x) {
	// 	cout<<"TA::TA(int ) called"<< endl;
	// }
	TA(int x):Student(x), Faculty(x), Person(x) {
		cout<<"TA::TA(int ) called"<< endl;
	}
};

 
int main()
{
    C c;
	TA ta1(30);
	// we can see that the constructor of person is called twice 
	// this means there are two copies of the person class in the object
	// to avoid this we need to use virtual key word
	// in this case, using virtual key word causes the default constructor be called
	// even when we called the parametrized constructor
	// to call the parametrized constructor we need to explicitly mention it in the TA constructor as done above
    return 0;
}
