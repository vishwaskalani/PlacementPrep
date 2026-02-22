#include <iostream>

template <int A, int B>
struct GCD {
    static const int value = GCD<B, A % B>::value;
};

template <int A>
struct GCD<A, 0> {
    static const int value = A;
};

int main() {
    std::cout << GCD<48, 18>::value << std::endl;
}