#include <bits/stdc++.h>
using namespace std;

template<typename T>
T mini(T x, T y){
	return (x < y) ? x : y;
}

int main(){

	cout<< mini<int>(1,2)<< "\n";

	// one important point that unsigned int have higher priority than the signed int

	// now let us look the difference between const and constexpr
	int z;
	cin>>z;
	const int x = z;
	// constexpr int y = z;
	// we can see that we can't use constexpr here because the value of z is not known at compile time
	// const variable can have its value set at runtime but constexpr variable must have its value set at compile time
	// x = 4; // this will give an error because x is a const variable
	constexpr int y = 4; // this is a compile time constant
	// y = 5; // this will give an error because y is a constexpr variable


	return 0;
}