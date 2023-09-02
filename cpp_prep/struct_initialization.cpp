#include <bits/stdc++.h>
using namespace std;

struct Employee
{
	int id {};
	string name {};
	double salary {};
};

struct Foo
{
	int a {};
	int b {1000}; //default value 
	int c {};
};


int main(){

	Employee Joe {2,"Joe",1300000};
	cout<<Joe.salary<<endl;
	// adding a new attribute in the struct might distort all this initialization

	//designated initialization
	Foo f1 {.a{3}, .c{5}};
	cout<<f1.a<<" "<<f1.b<<" "<<f1.c<<endl;
	// this way we can add any attribute later without any distortion

	// when we make an object without any value initialization, then its attributes are default value initialized 
	Foo f2;
	cout<<f2.a<<" "<<f2.b<<" "<<f2.c<<endl;

	// when we make an object with some initialization then its attributes are value initialized
	Foo f3 {2,3,4};
	cout<<f3.a<<" "<<f3.b<<" "<<f3.c<<endl;





	return 0;

}