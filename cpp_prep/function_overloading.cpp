#include <bits/stdc++.h>
using namespace std;

int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

int add(int x,int y,int z) //3 integers version
{ 
	return x+y+z;
}

void print(const int x)
{
     std::cout << x << '\n';
}

void print(double d)
{
     std::cout << d << '\n';
}

class X // this defines a new type called X
{
public:
    operator int() { return 0; } // Here's a user-defined conversion from X to int
};

void printn(char, int)
{
	std::cout << 'a' << '\n';
}

void printn(char, double)
{
	std::cout << 'b' << '\n';
}

void printn(char, float)
{
	std::cout << 'c' << '\n';
}


int main(){

	// there can be cases when we want our add function to add two integers
	// as well as two doubles

	//because the parameter type of these functions is different we will not get any error here

	cout<<"integer version result : "<<add(2,3)<<endl;
	cout<<"floating version result : "<<add(2.1,3.1)<<endl;
	cout<<"3 integer version result : "<<add(1,2,3)<<endl;

	// how overloaded functions can be differentiated
	//based on the number of parameters
	//based on the data types of the parameters
	//can't differentiate based on the return type

	//A function’s type signature (generally called a signature) is defined as the parts of the function header 
	//that are used for differentiation of the function.
	//In C++, this includes the function name, number of parameter, parameter type, and function-level qualifiers
	//It notably does not include the return type.


	//resolving ambiguity
	//some trivial conversions are simply done
	int x{4};
	print(x);
	//Converting a non-reference type to a reference type (or vice-versa) is also a trivial conversion.

	//numeric promotions for type conversions
	print('a'); // promoted to match print(int)
    print(true); // promoted to match print(int)
    print(4.5f); // promoted to match print(double)

	//after numeric promotions, it tries for numeric conversions

	//user defined conversions
	X y; // Here, we're creating an object of type X (named x)
    print(y); // x is converted to type int using the user-defined conversion from X to int
	//print(5L); //ambiguous call compiler error

	//chosing the best match
	printn('x', 'a');

	return 0;
}