#include <bits/stdc++.h>
using namespace std;

// this function decays the input to a pointer 
void printsize(int array[]){
	cout<<"The size printed is "<<sizeof(array)<<endl; // thus this will print the size of pointer that is 8 bytes
	// compiler warns this as well
}

// arrays within structs or classes don't decay to pointer
struct Mystruct{
	int arr[5];
};

void printstruct_arrsize(Mystruct& mystruct){
	cout<<"The size of array printed in this case is "<<sizeof(mystruct.arr)<<endl;
}

void printArrayByReference(const int (&arr)[5]) {
    std::cout << "Size of array inside the function: " << sizeof(arr) << " bytes\n";
}

int main(){

	int array[5]{ 9, 7, 5, 3, 1 };

    // print address of the array's first element
    cout << "Element 0 has address: " << &array[0] << '\n';

    // print the value of the pointer the array decays to
    cout << "The array decays to a pointer holding address: " << array << '\n';

	//dereferecing an array returns the first element of the array
	cout<<"Dereferencing the arry gives the first element: "<<*array<< '\n';

	// there are many difference between the pointer to the array and array itself
	cout<<"The size of array is "<<sizeof(array)<<endl;
	int* ptr{array};
	cout<<"The size of the pointer to the array is "<<sizeof(ptr)<<endl;
	// this is very interesting to note that the size of pointer on a 64 bit machine would be 8 bytes
	// but the size of pointer on a 32 bit machine would be 4 bytes

	// very imp to note differences
	std::cout << array << '\n';	 // type int[5], prints 0x7ffce64bf110
    std::cout << &array << '\n'; // type int(*)[5], prints 0x7ffce64bf110
	// printing array and the address of the array prints the same thing

    std::cout << '\n';

    std::cout << ptr << '\n';	 // type int*, prints 0x7ffce64bf110
    std::cout << &ptr << '\n';	 // type int**, prints 0x7ffce64bf108
	//printing the pointer and the address of the pointer prints different things
	printsize(array);

	Mystruct sample;
	printstruct_arrsize(sample); //prevents the decay of array to pointer
	printArrayByReference(array); //prevents the decay of array to pointer
	return 0;
}