#include <bits/stdc++.h>
using namespace std;

void print(unsigned int u) // note: unsigned
{
    std::cout << u << '\n';
}


int main(){

    std::cout << "Enter an integral value: ";
    int n{};
    std::cin >> n; // enter 5 or -5
    print(n);      // conversion to unsigned may or may not preserve value depending on the value

    constexpr int n1{ 5 };   // note: constexpr
    unsigned int u1 { n1 };  // okay: conversion is not narrowing due to exclusion clause

    // constexpr is a hint to the compiler that the expression can be evaluated at compile time
    // no need to wait for the run time
    // thus in this way narrowing conversions are not allowed

    // constexpr int n2 { -5 }; // note: constexpr
    // unsigned int u2 { n2 };  // compile error: conversion is narrowing due to value change

    float f { 1.23456789 }; // not a narrowing conversion, even though precision lost!

    return 0;
}

//KEY POINT : The key point is the use of constexpr
// Then we have that brace initialization doesn't produce an error when precision is lost