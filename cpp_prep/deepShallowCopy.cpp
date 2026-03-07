#include <bits/stdc++.h>
using namespace std;

class Box{

	public:

	int* value;

	Box(int v){
		value = new int(v);
	}

};

class BoxDeep {
	public:

	int* value;

	BoxDeep(int v){
		value = new int(v);
	}

	BoxDeep(const BoxDeep& other){
		value = new int(*other.value);
		// this is deep copy when you are actually copying the values itself and pointing to different memory regions
	}

	~BoxDeep(){
		delete value;
	}

};

int main(){

	Box b1(10);
	Box b2 = b1;

	*b2.value = 50; // shallow copy 
	// copies the value of members directly not the data they point 2

	cout<<*b1.value<<endl;

	// By default, shallow copy would happen
	// unless you have an explicity copying constructor

	return 0;
}