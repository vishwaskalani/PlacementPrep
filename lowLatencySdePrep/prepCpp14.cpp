#include <bits/stdc++.h>
using namespace std;

// char arrays vs strings

//When you pass a char array to a function, it decays into a pointer. It loses its "length" identity.
void printSize(char arr[]) {
    std::cout << sizeof(arr); // Outputs 8 (size of a pointer), NOT the array size!
}


int main(){

	char stackArr[] = "Hello"; // Size is 6 (H-e-l-l-o-\0)
	const char* ptr = "Hello"; // Pointer to a string literal

	// stackArr: Lives on the stack. You can modify stackArr[0] = 'Y'.
	// ptr: Points to Read-Only Data (the data segment). Attempting ptr[0] = 'Y' will usually cause a Segmentation Fault.


	// because printing functions look for the \0 characters
	char bad[3] = {'A', 'B', 'C'};
	cout << bad; // Will print ABC followed by random memory "garbage" until it hits a 0.


	// tricky pointer movement
	char arr[] = "Ghost";
	char* p = arr;

	*p++;   // Increments the pointer (moves to 'h'), then returns the old value 'G'
	(*p)++; // Increments the actual character (changes 'G' to 'H')

	return 0;
}