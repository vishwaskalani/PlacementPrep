#include <bits/stdc++.h>
using namespace std;

int main(){

    int x { 10 };
    int y { 4 };
    double d = x / y; // does integer division, initializes d with value 2.0
    cout<<d<<endl;
    // we need to explicitly type cast

    // mainly two types of explicit casting
    //C style cast

    double d1 { double(x) / y }; // convert x to a double so we get floating point division
    cout<<d1<<endl;
    //there is no compile time checking in c style cast
    //it may use different types of casting based on the context
    //one must avoid using c style casts


    // static cast
    char c { 'a' };
    std::cout << c << ' ' << static_cast<int>(c) << '\n'; // prints a 97
    //The main advantage of static_cast is that it provides compile-time type checking

    //static cast is intentionally less powerful and can't do things like below
    // it can't cast away the const of a variable that is convert a const type to non const type reference
    // const int z{ 5 };
	// int& ref{ static_cast<int&>(z) }; // invalid: will produce compilation error
	// ref = 6;
    
    return 0;
}

//KEY POINT : The key point is that one must avoid c style casts and use static casting