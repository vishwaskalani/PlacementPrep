#include <bits/stdc++.h>
using namespace std;

class Fraction
{
private:
    int m_numerator {};
    int m_denominator {};

public:
    // Fraction() // default constructor
    // {
    //     m_numerator = 0;
    //     m_denominator = 2;
    // }

	// Constructor with two parameters, one parameter having a default value
    // Fraction(int numerator, int denominator=1)
    // {
    //     assert(denominator != 0);
    //     m_numerator = numerator;
    //     m_denominator = denominator;
    // }

	// default constructor is redundant if we use constructor of this type
	Fraction(int numerator=0, int denominator=1)
    {
        assert(denominator != 0);

        m_numerator = numerator;
        m_denominator = denominator;
    }

    int getNumerator() { return m_numerator; }
    int getDenominator() { return m_denominator; }
    double getValue() { return static_cast<double>(m_numerator) / m_denominator; }
};

class Date
{
	private:
		int m_year{ 1900 };
		int m_month{ 1 };
		int m_day{ 1 };

	public:
		// Date() = default; // can declare default constructor like this or with empty braces
		Date(int year, int month, int day) // normal non-default constructor
		{
			m_year = year;
			m_month = month;
			m_day = day;
		}

		// No implicit constructor provided because we already defined our own constructor
};

class A
{
public:
    A() { std::cout << "A\n"; }
};

class B
{
public:
    B() { std::cout << "B\n"; }
private:
    A m_a; // B contains A as a member variable
};


int main(){

	Fraction fiveThirds{ 5, 3 }; // List initialization, calls Fraction(int, int)
	Fraction threeQuarters(3, 4); // Direct initialization, also calls Fraction(int, int)
	Fraction six{ 6 }; // calls Fraction(int, int) constructor, second parameter uses default value of 1
	Fraction seven(7);
	//Date date{}; //default constructor not there so error, default constructor won't be there if we define our own constructor without mentioning default
	B b;
	// private attributes are called first independent of their order of declaration
	//A
	//B will be printed

	return 0;
}