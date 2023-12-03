#include <bits/stdc++.h>
using namespace std;

template<int a,int b>
constexpr int gcd(){
	return gcd<b,a%b>();
}

template<int a>
constexpr int gcd<a>{
	return a;
}

int main(){
	static_assert(gcd<5,16>()==1);
	// static_assert(gcd<4,6>()==2);
}