#include <bits/stdc++.h>
using namespace std;

// understanding const and const expr
// const expr hints the compiler to evaluate the value at compile time
constexpr int product(int a, int b){
	return a*b;
}

// const means that the value of an object cannot be changed after initialization. The value of the initializer may be known at compile-time or runtime. 
// The const object can be evaluated at runtime.

// constexpr means that the object can be used in a constant expression. The value of the initializer must be known at compile-time. 
// The constexpr object can be evaluated at runtime or compile-time.

int main(){

	constexpr int ans = product(5, 10); // evaluated at compile time

	cout << ans << endl;

	const int a = 10;
	int b = 20; 
	const int sum = a + b; // evaluated at runtime
	// constexpr int sum2 = a + b; // error: b is not a constant expression

	const int arrSize = 5;
	int arr[arrSize]; // valid in C++11 and later, arrSize is a const but not a constexpr

	int x;
	cin >> x;
	const int y = x; // valid, y is a const but not a constexpr
	// constexpr int z = x; // error: x is not a constant expression

	// const expression if statements
	constexpr double gravity = 9.81; // m/s^2

	if constexpr (gravity > 10) { // evaluated at compile time
		cout << "High gravity environment" << endl; // You will not find this line in the assembly code written by the compiler
	} else {
		cout << "Normal gravity environment" << endl;
	}

	return 0;
}