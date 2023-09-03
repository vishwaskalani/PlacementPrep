#include <bits/stdc++.h>
using namespace std;

class DateClass1 // members are private by default
{
    int m_month {}; // private by default, can only be accessed by other members
    int m_day {}; // private by default, can only be accessed by other members
    int m_year {}; // private by default, can only be accessed by other members
};

class DateClass // members are private by default
{
    int m_month {}; // private by default, can only be accessed by other members
    int m_day {}; // private by default, can only be accessed by other members
    int m_year {}; // private by default, can only be accessed by other members

public:
    void setDate(int month, int day, int year) // public, can be accessed by anyone
    {
        // setDate() can access the private members of the class because it is a member of the class itself
        m_month = month;
        m_day = day;
        m_year = year;
    }

    void print() // public, can be accessed by anyone
    {
        std::cout << m_month << '/' << m_day << '/' << m_year;
    }

	// Note the addition of this function
	void copyFrom(const DateClass& d)
	{
		// Note that we can access the private members of d directly
		m_month = d.m_month;
		m_day = d.m_day;
		m_year = d.m_year;
	}
	// we are able to do this beacuse the access control works on a per class basis and not per object basis
	// so we can access all the private attributes of any object of that class type
};

int main()
{
    DateClass1 date1;
    // date1.m_month = 10; // error
    // date1.m_day = 14; // error
    // date1.m_year = 2020; // error

	// in general member variables are made private and member functions are made public

	DateClass date;
	date.setDate(10, 14, 2020); // okay, because setDate() is public

	DateClass copy {};
	copy.copyFrom(date); // okay, because copyFrom() is public
	copy.print();
	std::cout << '\n';


    return 0;
}