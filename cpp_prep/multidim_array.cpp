#include <bits/stdc++.h>
using namespace std;


int main(){
	int oned[] {1,2,3,4}; // this works, compiler figures out the length of this array
	int twod[][3] {{1,2,3},{2,3,4}}; //this also works, compiler can figure out the lft most length
	//int twod[][] {{1,2,3},{2,3,4}}; //this doesn't work
	return 0;
}