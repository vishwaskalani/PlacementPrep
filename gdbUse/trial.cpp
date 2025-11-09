#include <bits/stdc++.h>
using namespace std;

void incement(int &x){
	x++;
}

void decrement(int &x){
	x--;
}

void incement_and_decrement(int &x){
	incement(x);
	decrement(x);
	cout<<x<<endl;
}

int main(){

	int x = 0;

	incement_and_decrement(x);

	cout<<x<<endl;

	return 0;
}