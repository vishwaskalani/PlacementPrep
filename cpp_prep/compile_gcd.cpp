#include <iostream>
#include <type_traits>

// Primary template
template<int a, int b>
struct gcd {
    static constexpr int value = gcd<b, a % b>::value;
};

// Partial specialization for the base case
template<int a>
struct gcd<a, 0> {
    static constexpr int value = a;
};

int main() {
    // Static assertions to ensure compile-time evaluation
    static_assert(gcd<5, 16>::value == 1, "GCD of 5 and 16 should be 1");
    static_assert(gcd<4, 6>::value == 2, "GCD of 4 and 6 should be 2");
    static_assert(gcd<48, 18>::value == 6, "GCD of 48 and 18 should be 6");

    // Optionally, print the results at runtime
    std::cout << "GCD of 5 and 16 is " << gcd<5, 16>::value << std::endl;
    std::cout << "GCD of 4 and 6 is " << gcd<4, 6>::value << std::endl;
    std::cout << "GCD of 48 and 18 is " << gcd<48, 18>::value << std::endl;

    return 0;
}


// you can't avoid the static key word with constexpr because template metaprogramming requires value to be a static member to access it like ::
