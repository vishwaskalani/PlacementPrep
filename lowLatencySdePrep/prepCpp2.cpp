#include <bits/stdc++.h>
using namespace std;

int main(){

	// The address opertor
	int x = 2;
	cout<<"The address of x is "<<&x<<endl;

	// The dereference operator
	int y = 2;
	int* p = &y; // p is a pointer to an integer and it holds the address of y
	cout<<"The value of y is "<<*p<<endl; // dereferencing p gives the value of y

	// Pointers to pointers
	int z = 2;
	int* p1 = &z; // p1 is a pointer to an integer and it holds the address of z
	int** p2 = &p1; // p2 is a pointer to a pointer to an integer and it holds the address of p1
	cout<<"The value of z is "<<**p2<<endl; // dereferencing p2 twice gives the value of z

	// dynamically allocating memory for an array
	int* arr = new int[5]; // arr is a pointer to an integer and it holds the address of the first element of the array
	for(int i=0; i<5; i++){
		arr[i] = i+1; // assigning values to the array
	}
	delete[] arr; // deallocating the memory

	// smart pointers 
	// unique pointer : only one unique pointer can point to a memory location
	{
		unique_ptr<int> uptr1 = make_unique<int>(5); // uptr1 is a unique pointer to an integer and it holds the address of the integer 5
		cout<<"The value of the integer pointed by uptr1 is "<<*uptr1<<endl; // dereferencing uptr1 gives the value of the integer
		// unique_ptr<int> uptr2 = uptr1; // not allowed as only one unique pointer can point to a memory location
		unique_ptr<int> uptr2 = move(uptr1); // transferring the ownership of the memory from uptr1 to uptr2
		if(!uptr1){
			cout<<"uptr1 is null"<<endl;
		}
		cout<<"The value of the integer pointed by uptr2 is "<<*uptr2<<endl; // dereferencing uptr2 gives the value of the integer
	} // memory is automatically deallocated when the unique pointer goes out of scope

	// shared pointer : multiple shared pointers can point to a memory location
	{
		shared_ptr<int> sptr1 = make_shared<int>(10); // sptr1 is a shared pointer to an integer and it holds the address of the integer 10
		cout<<"The value of the integer pointed by sptr1 is "<<*sptr1<<endl; // dereferencing sptr1 gives the value of the integer
		cout<<"The reference count of sptr1 is "<<sptr1.use_count()<<endl; // reference count is 1
		shared_ptr<int> sptr2 = sptr1; // allowed as multiple shared pointers can point to a memory location
		cout<<"The value of the integer pointed by sptr2 is "<<*sptr2<<endl; // dereferencing sptr2 gives the value of the integer
		cout<<"The reference count of sptr1 is "<<sptr1.use_count()<<endl; // reference count is 2
		cout<<"The reference count of sptr2 is "<<sptr2.use_count()<<endl; // reference count is 2
	} // memory is automatically deallocated when the last shared pointer goes out of scope

	// weak pointer : a weak pointer is a special type of smart pointer that does not affect the reference count of a shared pointer
	{
		shared_ptr<int> sptr1 = make_shared<int>(15); // sptr1 is a shared pointer to an integer and it holds the address of the integer 15
		weak_ptr<int> wptr1 = sptr1; // wptr1 is a weak pointer to an integer and it holds the address of the integer 15
		cout<<"The value of the integer pointed by sptr1 is "<<*sptr1<<endl; // dereferencing sptr1 gives the value of the integer
		cout<<"The reference count of sptr1 is "<<sptr1.use_count()<<endl; // reference count is 1
		if(auto sptr2 = wptr1.lock()){ // lock() returns a shared pointer if the memory is still available
			cout<<"The value of the integer pointed by sptr2 is "<<*sptr2<<endl; // dereferencing sptr2 gives the value of the integer
			cout<<"The reference count of sptr1 is "<<sptr1.use_count()<<endl; // reference count is 2
			cout<<"The reference count of sptr2 is "<<sptr2.use_count()<<endl; // reference count is 2
		} else {
			cout<<"The memory has been deallocated"<<endl;
		}
	} // memory is automatically deallocated when the last shared pointer goes out of scope


	return 0;
}