#include <bits/stdc++.h>
using namespace std;

int main(){

    int *ptr = new int;
    *ptr = 40;
    delete ptr;

    //using a pointer after deleting is called dangling pointer in C++
    // best practice is to make the pointer null pointer
    // so that it is not dangling
    // *ptr = 54;
    // int a = *ptr;
    // cout<<a<<endl;
    // may get an unexpected crash due to this

    //it is due to these issues, C++ introduced new types of pointers unique_ptr and shared_ptr
    // only one pointer can have the ownership of a resoruce
    // you can move the ownership
    unique_ptr<int> un = make_unique<int>(42);
    cout<<"Value at un is "<<*un<<endl;
    unique_ptr<int> new_un = move(un);
    cout<<"Value at new un is "<<*new_un<<endl;
    if(un==nullptr){
        cout<<"un is null now"<<'\n';
    }
    else{
        cout<<"un is not null now"<<"\n";
    }
    shared_ptr<int> sp = make_shared<int>(42);
    cout<<"Value at sp is "<<*sp<<endl;
    // this loop will not increase the reference count because each time a new pointer is contructed
    // it is destroyed once it goes out of the scope
    for(int i=0; i<10; i++){
        shared_ptr<int> new_sp = sp;
    }
    //this will increase the count of the pointers owning the same resource
    shared_ptr<int> new_sp = sp;
    cout<<"The count of ptrs with the same resources are : "<<sp.use_count()<<'\n';
    return 0;
}