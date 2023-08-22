#include <iostream>

template <typename T> // this is the template parameter declaration

T max(T x, T y) // this is the function template definition for max<T>
{
    return (x < y) ? y : x;
}

int main(){

	// this is called function template instantiation
	std::cout << max<int>(1, 2) << '\n';    // instantiates and calls function max<int>(int, int)
    std::cout << max<int>(4, 3) << '\n';    // calls already instantiated function max<int>(int, int)
    std::cout << max<double>(1.1, 2.2) << '\n'; // instantiates and calls function max<double>(double, double)
	return 0;
}