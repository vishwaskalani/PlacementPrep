#include <bits/stdc++.h>
using namespace std;

class A
{
public:
	virtual string getName1(int x) { return "A"; }
	virtual string getName2(int x) { return "A"; }
	virtual string getName3(int x) { return "A"; }
};

class B : public A
{
public:
	// string getName1(short int x) override { return "B"; } // compile error, function is not an override
	// string getName2(int x) const override { return "B"; } // compile error, function is not an override
	string getName3(int x) override final { return "B"; } // okay, function is an override of A::getName3(int)

};

class C final: public B
{
public:
	// string getName3(int x) override { return "C"; } // compile error: overrides B::getName(int x), which is final

};

// we get compile error here because class C has been labelled final 
// class D : public C
// {
// public:
// };

int main(){

	// as we can see that using override everytime we use virtual function
	// can help us debug where we had override and where we did not

	//final key word can be used when we want to stop the overriding of the functions

	// we can use this with class as well, when we want to stop the inheritence from that class

	return 0;
}