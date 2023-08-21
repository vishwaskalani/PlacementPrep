#include <bits/stdc++.h>
using namespace std;

int main(){

    using Miles = long; // define Miles as an alias for type long
    using Speed = long; // define Speed as an alias for type long

    Miles distance { 5 }; // distance is actually just a long
    Speed mhz  { 3200 };  // mhz is actually just a long

    // The following is syntactically valid (but semantically meaningless)
    distance = mhz;
    //a type alias defined inside a block has block scope and is usable only within that block


    // we can have global scope for types using header files like this
    //the block of ifndef,define,endif is include guard and prevents duplicate inclusion error

    // #ifndef MYTYPES_H
    // #define MYTYPES_H

    //     using Miles = long;
    //     using Speed = long;

    // #endif

    // The following aliases are identical
    typedef long Miles; // this is an older way of creating aliases
    using Miles = long;

    return 0;
}


// KEY POINT : The above are the ways of creating type aliases
// in typedef we write the name of base datatype first and then the new data type