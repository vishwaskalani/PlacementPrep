#include <bits/stdc++.h>
using namespace std;

int main(){

    // Interconversion of numerical types except those which are numerical promotions
    short s = 3; // convert int to short
    long l = 3; // convert int to long
    char ch = s; // convert short to char
    unsigned int u = 3; // convert int to unsigned int

    // safe numeric conversions examples where value can be preserved
    // int -> long
    // short -> double

    int n = static_cast<int>(static_cast<long>(3)); // convert int 3 to long and back
    std::cout << n << '\n';                         // prints 3

    char c = static_cast<char>(static_cast<double>('c')); // convert 'c' to double and back
    std::cout << c << '\n';                               // prints 'c'

    //static_cast serves to make the type conversions explicit and clear, making the code easier to understand and less prone to unintended type conversion surprises


    // unsafe conversion - compiler gives warnings
    // int n1 { 5 };
    // unsigned int u1 { n1 }; // okay: will be converted to unsigned int 5 (value preserved)

    // int n2 { -5 };
    // unsigned int u2 { n2 }; // bad: will result in large integer outside range of signed int

    // this conversion can still be lossless
    int ui = static_cast<int>(static_cast<unsigned int>(-5)); // convert '-5' to unsigned and back
    std::cout << ui << '\n'; // prints -5

    // but conversions like float -> int -> float will be lossy
    float ff = static_cast<float>(static_cast<int>(3.5f));
    cout<<ff<<endl;

    // unexpected results
    int ii{ 3000 };
    char cc = ii; // chars have range -128 to 127

    std::cout << static_cast<int>(cc) << '\n';


    return 0;
}

// KEY POINT : The key point is that lossless conversions can be reverted
// Out of range conversions will have unexpected behaviour
// signed int -> unsigned int -> signed int is possible
// float -> int -> float will obviously not be accurate