#include<bits/stdc++.h>
using namespace std;

class A{

public:
	A(){
		cout<<"Constructor"<<endl;
		throw runtime_error("Run time constructor");
	}
	// destructor can't throw exceptions
	// they are defaulted to no except
	~A(){
		cout<<"Destructor"<<endl;
		throw runtime_error("Run time destructor");
	}

};

int main(){
	try{
		cout<<"Hi does it come here"<<endl;
		throw runtime_error("Run time problem created");
	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}
	try{
		A a;
	}
	catch(exception& e){
		cout<<e.what()<<endl;
	}
	return 0;
}