#include <bits/stdc++.h>
using namespace std;

class Something
{
public:
    int m_value {};

    Something(): m_value{0} { }

    void setValue(int value) { m_value = value; }
    int getValue_nconst() { return m_value ; }
    int getValue() const { return m_value ; } // adding such a const key word makes it a const member function
	int outside() const;
};

int Something::outside() const // and here
{
    return m_value;
}

class Date
{
private:
    int m_year {};
    int m_month {};
    int m_day {};

public:
    Date(int year, int month, int day)
    {
        setDate(year, month, day);
    }

    void setDate(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
    }

    int getYear() const { return m_year; }
    int getMonth() const { return m_month; }
    int getDay() const { return m_day; }
	// we can overload the function in such a way that the const and non const variants of the function are different
	int getDay() {return m_day;}
};

// note: We're passing date by const reference here to avoid making a copy of date
// passing by const reference in a function means the object is treated as a const class object 
void printDate(const Date& date)
{
    std::cout << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << '\n';
}



int main(){

	const Something something{}; // calls default constructor

    // something.m_value = 5; // compiler error: violates const
    // something.setValue(5); // compiler error: violates const
	// cout << something.getValue_ncost(); // this is also a compile error as this function has not been marked as const member function

	//A const member function is a member function that guarantees it will not modify the object 
	//or call any non-const member functions (as they may modify the object).

	//For member functions defined outside of the class definition,
	//the const keyword must be used on both the function prototype in the class definition and on the function definition:

	cout<<something.getValue()<<endl;
	return 0;
}