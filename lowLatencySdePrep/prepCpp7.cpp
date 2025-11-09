#include <bits/stdc++.h>
using namespace std;

// understanding type conversions in C++

int main(){

	// conversion of arithmetric operands to the types as per the priority order : double > float > long long > long > int > short > char
	char c = 'a';
	// for char the ascii value is considered
	int i = 10;
	double d = 5.5;
	cout<< typeid(c+i+d).name() << endl; // double
	cout<< c+i+d << endl; // 112.5
	cout<< typeid(c+i).name() << endl; // int

	// unsigned data types have higher priority
	cout<< typeid(5u - 10).name() << endl; // unsigned int
	cout<< 5u - 10 << endl; // large value because of the conversion to unsigned int

	// c style casting vs static casting
	// c style casting
	int x { 10 };
	int y { 4 };
	double val1 = x / y; // does integer division, initializes val1 with value 2.0
	cout<<val1<<endl;
	// we need to explicitly type cast
	//C style cast
	double val2 { double(x) / y }; // convert x to a double so we get floating point division
	cout<<val2<<endl;
	//there is no compile time checking in c style cast
	//it may use different types of casting based on the context
	//one must avoid using c style casts
	// static cast
	char ch { 'a' };
	std::cout << ch << ' ' << static_cast<int>(ch) << '\n'; // prints a 97
	//The main advantage of static_cast is that it provides compile-time type checking
	//static cast is intentionally less powerful and can't do things like below
	// it can't cast away the const of a variable that is convert a const type to non const type reference
	// const int z{ 5 };
	// int& ref{ static_cast<int&>(z) }; // invalid: will produce compilation error

	// very interesting float double situation
	double f {5.0f}; // numeric promotion float to double

	// float g {f}; // can't happen as it is a narrowing conversion

	float h {7.0}; // can happen as 7.0 is a constant expression and can be represented exactly as a float

	return 0;
}