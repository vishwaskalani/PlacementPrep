#include <bits/stdc++.h>
using namespace std;

class Something
{
private:
    static int s_value;

public:
	static int getValue(){
		return s_value;
	}

};

int Something::s_value{ 1 }; // initializer, this is okay even though s_value is private since it's a definition


int main(){

	// how will we access a static private variable
	// we can have a static member function which can again be independent of the object of that class	
	cout<<Something::getValue()<<endl;

	// some important points about static member functions
	// They don't have any this pointer as they are not associated with any object
	// They don't have access to the non static members of the class because non static members are associated with objects

	return 0;
}