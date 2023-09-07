#include <bits/stdc++.h>
using namespace std;

class Storage
{
private:
    int m_nValue {};
    double m_dValue {};
public:
    Storage(int nValue, double dValue)
       : m_nValue { nValue }, m_dValue { dValue }
    {
    }

    // Make the Display class a friend of Storage
    friend class Display;
};

class Display
{
private:
    bool m_displayIntFirst;

public:
    Display(bool displayIntFirst)
         : m_displayIntFirst { displayIntFirst }
    {
    }

    void displayItem(const Storage& storage)
    {
        if (m_displayIntFirst)
            std::cout << storage.m_nValue << ' ' << storage.m_dValue << '\n';
        else // display double first
            std::cout << storage.m_dValue << ' ' << storage.m_nValue << '\n';
    }
};

int main(){

	Storage storage{5, 6.7};
    Display display{false};

    display.displayItem(storage);

	// friendship is not a mutual relationship
	//display is the friend of storage but storage is not a friend of display unless declared


	// we can have a particular function of a class as the friend function instead of making the entire 
	// class as friend using the scoping operator from the class and writing the function as friend as usual

	return 0;
}