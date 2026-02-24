#include <bits/stdc++.h>
using namespace std;

// concept of malloc and free

// When you call malloc, the OS doesn't just hand you bytes. The C standard library manages a "free list."

// When malloc allocates 20 bytes, it often actually carves out 24 or 32 bytes. 
// The extra space (usually just before the pointer you receive) stores metadata, like the size of the block.

// This is why free(ptr) doesn't need a size argument—it just looks at the hidden metadata header right before the address you passed.

// function signature of malloc : void* malloc(size_t size);, void* can be casted to pointer of any type

// function signature of free : void free(void* ptr);

int main(){

	int* ptr = (int*)malloc(5 * sizeof(int)); // Allocates raw bytes

	if (ptr != nullptr) {
		ptr[0] = 10;
		free(ptr); // Releases memory back to the heap manager
	}

	return 0;
}