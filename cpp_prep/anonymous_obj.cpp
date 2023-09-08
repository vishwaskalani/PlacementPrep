#include <bits/stdc++.h>
using namespace std;

int sum(int x,int y){
	return x+y;// this is like an anonymous object
}

class Cents
{
private:
    int m_cents{};

public:
    Cents(int cents)
        : m_cents { cents }
    {}

    int getCents() const { return m_cents; }
};

void print(const Cents& cents)
{
   std::cout << cents.getCents() << " cents\n";
}


Cents add(const Cents& c1, const Cents& c2)
{
    // List initialization looks at the return type of the function
    // and creates the correct object accordingly.
    return { c1.getCents() + c2.getCents() }; // return anonymous Cents value
}


int main(){
	//we can have anonymous objects with classes as well
	print(Cents{ 6 }); // Note: Now we're passing an anonymous Cents value
	Cents cents1{ 6 };
    Cents cents2{ 8 };
    cout << "I have " << add(cents1, cents2).getCents() << " cents.\n"; // print anonymous Cents value
	return 0;
}