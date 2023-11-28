#include <bits/stdc++.h>
using namespace std;

enum StudentNames
{
	vishwas,
	viraj,
	tushar,
	aman,
	ishaan,
	maxstudents
};

enum class FriendNames
{
	vishwas,
	viraj,
	tushar,
	aman,
	ishaan,
	maxfriends
};

// gives compile error as the array type is const
// void passArray(const int prime[5]){
// 	prime[0] = 2;
// 	prime[1] = 3;
// }

int main(){

	int testscores[maxstudents] {};
	testscores[vishwas] = 95;
	// no problem in using enumerations without classes as they can easily be converted to int

	// int testscore_new[maxfriends] {}; -- this is not possible in enum classes
	int testscore_new[static_cast<int>(FriendNames::maxfriends)]{};
	// for enum classes u have to statically cast them to int
	// enum classes are basically scoped enumerations and we can't use them without the scoping operator ::

	return 0;
}