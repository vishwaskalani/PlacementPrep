#include <bits/stdc++.h>
using namespace std;

// understanding lvalues and rvalues

int GetValue(){
	return 10;
}

void PrintString(const string& str){
	// both lvalue and rvalue can be passed to this function
	cout<<"Lvalue/Rvalue: "<<str<<endl;
}

void PrintStringRef(string& str){
	// only lvalue can be passed to this function
	cout<<"Lvalue: "<<str<<endl;
}

void PrintStringRRef(string&& str){
	// only rvalue can be passed to this function
	cout<<"Rvalue: "<<str<<endl;
}

int main(){

	int i = 10;
	// i is an lvalue as it has a memory address
	// 10 is an rvalue as it does not have a memory address

	int a = i;
	// a and i are lvalues

	int b = GetValue();
	// b is an lvalue
	// GetValue() = 5; // cannot assign a value to an rvalue

	// you can assign value to a reference of an lvalue by using the keyword const
	const int& ref = 5; // ref is a reference to the rvalue 5

	// rvalue references
	int&& rref = GetValue(); // rref is an rvalue reference to the rvalue returned by GetValue()

	string s1 = "Hello";
	string s2 = "Systems Engineering";
	string s3 = s1 + " " + s2; // s1 + " " + s2 is an rvalue

	PrintString(s1); // lvalue
	PrintString(s1 + " " + s2); // rvalue
	PrintStringRef(s1); // lvalue
	// PrintStringRef(s1 + " " + s2); // error: cannot bind rvalue to lvalue reference
	PrintStringRRef(s1 + " " + s2); // rvalue

	return 0;
}