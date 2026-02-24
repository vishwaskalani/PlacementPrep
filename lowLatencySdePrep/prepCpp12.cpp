#include <bits/stdc++.h>
using namespace std;

// sizeof concept array vs vector
// The sizeof operator is evaluated at compile-time. It tells you how many bytes a variable occupies in the stack, not how much heap memory it manages.

int main(){

	int arr[50];
	vector<int> vec(50);
	cout<<"The size of array is "<<sizeof(arr)<<endl;
	cout<<"The size of vector is "<<sizeof(vec)<<endl;

	return 0;
}