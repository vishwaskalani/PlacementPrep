#include <bits/stdc++.h>
using namespace std;

void printDouble(double d)
{
    std::cout << d << '\n';
}


void printInt(int x)
{
    std::cout << x << '\n';
}


int main(){

    printDouble(5.0); // no conversion necessary
    printDouble(4.0f); // numeric promotion of float to double

    // by doing numerical promotion compiler is able to optimize the execution of code

    // INTEGRAL PROMOTIONS
    // signed char -> int
    // unsigned char -> int
    // signed short -> int
    // bool -> int
    // remember int to ll is not a numerical promotion 
    // it is a numerical conversion
    short s{ 3 };
    printInt(s); 

    char c{'z'};
    printInt(c); //will print the ascii value

    return 0;
}

// KEY POINT : The key point is that some conversions of data types are called numeric promotions
//some functions which can take in int as input will allow even char as input 
//will have their ascii value