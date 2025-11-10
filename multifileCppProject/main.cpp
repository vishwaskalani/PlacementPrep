#include "b1.h"
#include "d1.h"
#include "d2.h"

int main() {
	B1* obj1 = new B1();
	B1* obj2 = new D1();
	B1* obj3 = new D2();

	obj1->display(); // Calls B1's display
	obj2->display(); // Calls D1's display
	obj3->display(); // Calls D2's display

	delete obj1;
	delete obj2;
	delete obj3;

	return 0;
}