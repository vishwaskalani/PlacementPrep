#include<bits/stdc++.h>
using namespace std;
class ClassA; // Forward declaration of ClassA
class ClassB; // Forward declaration of ClassB

class ClassA {
private:
    int privateVarA;

public:
    ClassA(int value) : privateVarA(value) {}

    friend void FriendFunction(ClassA&, ClassB&);
};

class ClassB {
private:
    int privateVarB;

public:
    ClassB(int value) : privateVarB(value) {}

    friend void FriendFunction(ClassA&, ClassB&);
};

// Define the friend function
void FriendFunction(ClassA& objA, ClassB& objB) {
    // The friend function can access private members of both ClassA and ClassB
    int valueA = objA.privateVarA;
    int valueB = objB.privateVarB;

    std::cout << "Value of privateVarA in ClassA: " << valueA << std::endl;
    std::cout << "Value of privateVarB in ClassB: " << valueB << std::endl;
}

int main() {
    ClassA objA(42);
    ClassB objB(73);

    FriendFunction(objA, objB); // Call the friend function to access private members of both classes

    return 0;
}
