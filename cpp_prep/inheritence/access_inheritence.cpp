#include <bits/stdc++.h>
using namespace std;

class Base
{
public:
    int m_public {}; // can be accessed by anybody
protected:
    int m_protected {}; // can be accessed by Base members, friends, and derived classes
	// can't be accessed outside the class
private:
    int m_private {}; // can only be accessed by Base members and friends (but not derived classes)
};

class Derived: public Base
// this is public inheritence
{
public:
    Derived()
    {
        m_public = 1; // allowed: can access public base members from derived class
        m_protected = 2; // allowed: can access protected base members from derived class
        // m_private = 3; // not allowed: can not access private base members from derived class
    }
};

// Inherit from Base publicly
class Pub: public Base
{
	// access specifier in base class     // access specifier in inherited class
	// public									public
	// protected								protected
	// private									not accessible
	public:
    Pub()
    {
        m_public = 1; // okay: m_public was inherited as public
        m_protected = 2; // okay: m_protected was inherited as protected
        // m_private = 3; // not okay: m_private is inaccessible from derived class
    }
};

// Inherit from Base protectedly
class Pro: protected Base
{
	// access specifier in base class     // access specifier in inherited class
	// public									protected
	// protected								protected
	// private									not accessible
};

// Inherit from Base privately
class Pri: private Base
{
	// access specifier in base class     // access specifier in inherited class
	// public									private
	// protected								private
	// private		
	public:
	Pri()
    {
        m_public = 1; // okay: m_public is now private in Pri
        m_protected = 2; // okay: m_protected is now private in Pri
        // m_private = 3; // not okay: derived classes can't access private members in the base class
    }
};

class Def: Base // Defaults to private inheritance
{
};

int main()
{
    Base base;
    base.m_public = 1; // allowed: can access public members from outside class
    // base.m_protected = 2; // not allowed: can not access protected members from outside class
    // base.m_private = 3; // not allowed: can not access private members from outside class

	// Outside access uses the access specifiers of the class being accessed.
    base.m_public = 1; // okay: m_public is public in Base
    //base.m_protected = 2; // not okay: m_protected is protected in Base
    //base.m_private = 3; // not okay: m_private is private in Base

    Pub pub;
    pub.m_public = 1; // okay: m_public is public in Pub
    // pub.m_protected = 2; // not okay: m_protected is protected in Pub
    // pub.m_private = 3; // not okay: m_private is inaccessible in Pub

	Pri pri;
    //pri.m_public = 1; // not okay: m_public is now private in Pri
    //pri.m_protected = 2; // not okay: m_protected is now private in Pri
    //pri.m_private = 3; // not okay: m_private is inaccessible in Pri

    return 0;
}