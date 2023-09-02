#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Pair
{
    T first{};
    T second{};
};

// using functions along with the templates
template <typename T>
constexpr T max(Pair<T> p)
{
    return (p.first < p.second ? p.second : p.first);
}

// class template with multiple template types
template <typename T, typename U>
struct Pair_new
{
    T first{};
    U second{};
};


template <typename T, typename U>
void print(Pair_new<T, U> p)
{
    std::cout << '[' << p.first << ", " << p.second << ']'<<"\n";
}



int main(){

	Pair<int> p{3,4};
	cout<<p.first<<" "<<p.second<<endl;

	Pair<int> p1{ 5, 6 };
    std::cout << max<int>(p1) << " is larger\n"; // explicit call to max<int>

    Pair<double> p2{ 1.2, 3.4 };
    std::cout << max(p2) << " is larger\n"; // call to max<double> using template argument deduction (prefer this)

	Pair_new<string,double> p3{"vishwas",33};
	print(p3);
	return 0;
}