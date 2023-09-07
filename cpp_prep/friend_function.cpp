#include <bits/stdc++.h>
using namespace std;

class Accumulator
{
private:
    int m_value { 0 };

public:
    void add(int value) { m_value += value; }

    // Make the reset() function a friend of this class
    friend void reset(Accumulator& accumulator);
};

// reset() is now a friend of the Accumulator class
void reset(Accumulator& accumulator)
{
    // And can access the private data of Accumulator objects
    accumulator.m_value = 0;
}


class Value
{
private:
    int m_value{};

public:
    Value(int value)
        : m_value{ value }
    {
    }
	// const here means the object would not be altered in the function
    friend bool isEqual(const Value& value1, const Value& value2);
};

bool isEqual(const Value& value1, const Value& value2)
{
    return (value1.m_value == value2.m_value);
}


int main(){
	//A friend function is a function that can access the private members of a class 
	//as though it was a member of that class. 
	Accumulator acc;
    acc.add(5); // add 5 to the accumulator
    reset(acc); // reset the accumulator to 0

	Value v1{ 5 };
    Value v2{ 6 };
    cout << boolalpha << isEqual(v1, v2)<<endl;
	// boolalpha prints the boolean value as either true or false

	// A function can be a friend of more than one class at the same time. 

	return 0;
}