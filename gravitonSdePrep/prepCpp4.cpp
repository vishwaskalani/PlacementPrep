#include <bits/stdc++.h>
using namespace std;

// template programming
template<typename T>
void print(T a){
	cout<<a<<endl;
}

// this won't give an error as the function below doesn't exist until we call it
template<typename U>
void printError(U a){
	cout<<b<<endl; // b is not defined
}

int main(){

	print(5);
	print(5.5);
	print("vishwas");
	print<int>(6); // explicit call to print<int>

	return 0;
}