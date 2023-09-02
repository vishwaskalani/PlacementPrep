#include <bits/stdc++.h>
using namespace std;


// we can have nested intitialization of structs
struct Student
{
	struct College
	{
		string name {};
		int id {};
	};
	string name {};
	int rollno {};
};

// size of struct
struct Foo
{
	short a {};
	int b {};
	double c {};
};

struct Foo1
{
    short a{}; // will have 2 bytes of padding after a
    int b{};
    short c{}; // will have 2 bytes of padding after c
};

struct Foo2
{
    int b{};
    short a{};
    short c{};
};
// we expect the size of Foo1 and Foo2 same but actually they are not
// infact Foo2 is smaller in size

int main(){

	cout<<"The size of short is "<<sizeof(short)<<endl; //2 bytes
	cout<<"The size of int is "<<sizeof(int)<<endl; //4 bytes
	cout<<"The size of double is "<<sizeof(double)<<endl; //8 bytes
	cout<<"The size of Foo is "<<sizeof(Foo)<<endl; //16 bytes
	// the size of struct is not necessarily same as the sum of size of its attributes
	// compiler pads into the struct to make its use more efficient
	cout<<"The size of Foo1 is "<<sizeof(Foo1)<<endl; // 12 bytes
	cout<<"The size of Foo1 is "<<sizeof(Foo2)<<endl; // 8 bytes

	return 0;
}