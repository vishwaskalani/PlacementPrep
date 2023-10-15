// C++ allows us to overload operators like functions
// however there are certain operators which can't be overloaded
// Example :: scoping operator, sizeof operator, member selector . operator, member pointer selector *, ternary operator ?:
#include <iostream>
using namespace std;
class Complex{

private:
	int real, imag;
public:
	Complex(){
		real = 0;
		imag = 0;
	}
	Complex(int r,int i){
		real = r;
		imag = i;
	}
	void print(){
		cout<<real<<"+"<<imag<<"i"<<endl;
	}

	//operator overloading syntax
	Complex operator +(Complex c){
		// this is how we overload a binary operator
		Complex temp;
		temp.real = real+c.real;
		temp.imag = imag+c.imag;
		return temp;
	}
};


class Weight{

private:
	int kg;
public:
	Weight(){
		kg = 0;
	}
	Weight(int x){
		kg = x;
	}
	void printWeight(){
		cout<<"weight is "<<kg<<endl;
	}

	//overloading preincrement operator
	void operator ++(){
		++kg;
	}

	//overloading postincrement operator
	void operator ++(int){
		kg++;
	}

};


int main(){
	Complex c1(5,4);
	Complex c2(2,3);
	Complex c3;
	// we want to achieve this functionality
	c3 = c1+c2;
	c3.print();

	Weight w(5);
	w.printWeight();
	++w;
	w.printWeight();
	w++;
	w.printWeight();
	return 0;
}