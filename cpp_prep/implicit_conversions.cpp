#include <bits/stdc++.h>
using namespace std;

float val(){
    return 5.2;
}

int main(){
    // implicit type conversion
    double d{3};
    cout<<d<<endl;
    d = 6;
    cout<<d<<endl;

    //implicit type conversion happens when return type of function is different than returned
    int x = val();
    cout<<x<<endl;
    
    // int y { 3.5 }; // brace-initialization disallows conversions that result in data loss

    int z = 3.5; // this sort of initialization is allowed even with data loss

    return 0;
}

// KEY POINT : The key point is that there exists a different sort of intialization in c++
// It is called brace initialization
//It disallows initialization with data loss