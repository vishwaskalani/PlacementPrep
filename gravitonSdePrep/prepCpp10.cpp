#include <bits/stdc++.h>
using namespace std;

// understanding template programming and concepts like CRTP

// template used for type deduction
template<typename T>
T add(T a, T b){
	return a+b;
}

// template parameters for non-type arguments
template<typename T, size_t size>
class Array{
	T arr[size];
};

// compile time gcd computation using template metaprogramming
template<int A, int B>
struct GCD{
	static const int value = GCD<B, A % B>::value;
};

template<int A>
struct GCD<A, 0>{
	static const int value = A;
};

// the key word static is important in the above example because 
// it ensures that the value is associated with the class itself rather than with any particular instance of the class.
// This means that you can access the value without creating an object of the class. and can be done at compile time

// Curiously Recurring Template Pattern (CRTP)
template<typename Derived>
class Base{
	public:
		void interface(){
			static_cast<Derived*>(this)->implementation();
		}

		void implementation(){
			cout<<"Base implementation"<<endl;
		}
};

class Derived : public Base<Derived>{
	public:
		void implementation(){
			cout<<"Derived implementation"<<endl;
		}
};

// crtp with multiple derived classes
template<typename Derived1, typename Derived2>
class MultiBase{
	public:
		void interface1(){
			static_cast<Derived1*>(this)->implementation1();
		}

		void interface2(){
			static_cast<Derived2*>(this)->implementation2();
		}
};

template<typename Derived2>
class Derived1 : public MultiBase<Derived1, Derived2>{
	public:
		void implementation1(){
			cout<<"Derived1 implementation1"<<endl;
		}
};

template<typename Derived1>
class Derived2 : public MultiBase<Derived1, Derived2>{
	public:
		void implementation2(){
			cout<<"Derived2 implementation2"<<endl;
		}
};


int main(){

	cout<<add(10, 20)<<endl; // works fine
	cout<<add(10.5, 20.3)<<endl; // works fine

	Array<int, 5> arr; // works fine

	cout<<GCD<48, 18>::value<<endl; // works fine

	Derived d;
	d.interface(); // works fine

	Base<Derived> *b = &d;
	b->interface(); // works fine

	Base<Derived> b2;
	b2.interface(); // works fine

	Base<Derived> b3;
	b3.implementation(); // works fine

	// Derived1<Derived2<Derived1<void>>> d1;
	// d1.interface1();
	// Derived2<Derived1<Derived2<void>>> d2;
	// d2.interface2(); // works fine
	// doesn't work because of circular dependency

	return 0;
}