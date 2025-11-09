#include <bits/stdc++.h>
using namespace std;

// underdstanding the use of friend functions and classes

class Base{

	int x;

public:

	Base(int val):x(val){}

	friend void func(Base &); // friend function declaration

	friend class Derived; // friend class declaration


};

void func(Base &b){

	// cout<<b.x; // error: 'int Base::x' is private within this context
	cout<<b.x; // works fine
}

class Derived{
public:

	void display(Base &b){

		cout<<b.x; // works fine
	}
};


int main(){

	Base b(10);
	func(b); // works fine
	Derived d;
	d.display(b); // works fine


	return 0;
}