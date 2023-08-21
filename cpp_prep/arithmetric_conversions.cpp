#include <bits/stdc++.h>
using namespace std;

int main(){
    // arithmetic conversion of some data types to higher priority data types
    int i{ 2 };
    double d{ 3.5 };
    std::cout << typeid(i + d).name() << ' ' << i + d << '\n'; // show us the type of i + d

    // some data types are not in the priority list and they are simply numerically promoted
    short a{ 4 };
    short b{ 5 };
    std::cout << typeid(a + b).name() << ' ' << a + b << '\n'; // show us the type of a + b
    // here short is numerically promoted to int

    std::cout << typeid(5u-10).name() << ' ' << 5u - 10 << '\n'; // 5u means treat 5 as an unsigned integer
    //unsigned int has higher priority therefore answer would be large

    std::cout << std::boolalpha << (-3 < 5u) << '\n';
    // might intuitively look true but is false
    // unsigned int or datatypes have higher priority
    return 0;
}

//KEY POINT : The key point is that there are some priority based conversions in arithmetic operators
// unsigned data types have higher priority