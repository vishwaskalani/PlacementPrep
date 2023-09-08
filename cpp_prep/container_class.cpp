#include <bits/stdc++.h>
#include "IntArray.h"
using namespace std;

int main(){
	// Value containers are compositions that store copies of the objects that they are holding 
	// (and thus are responsible for creating and destroying those copies). 
	
	// Reference containers are aggregations that store pointers or references to other objects 
	// (and thus are not responsible for creation or destruction of those objects).

	IntArray arr(5);
	for(int i=0; i<5; i++){
		arr[i] = i;
	}
	cout<<"The length of the array is "<<arr.getLength()<<endl;
	for(int i=0; i<5; i++){
		cout<<"element at index i is "<<arr[i]<<endl;
	}
	return 0;
}