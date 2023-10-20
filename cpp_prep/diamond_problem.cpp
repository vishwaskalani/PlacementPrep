#include<iostream>
using namespace std;

class A
{
	int x;
public:
	void setX(int i) {x = i;}
	void print() { cout << x<<endl; }
};

// class B: public A
// {
// public:
// 	B() { setX(10); }
// };

class B: virtual public A
{
public:
	B() { setX(10); }
};

// class C: public A 
// {
// public:
// 	C() { setX(20); }
// };

class C: virtual public A 
{
public:
	C() { setX(20); }
};

class D: public B, public C {
};

int main()
{
	D d;
	d.print();
	// without virtual keyword this program would not compile because of the ambiguity
	return 0;
}
