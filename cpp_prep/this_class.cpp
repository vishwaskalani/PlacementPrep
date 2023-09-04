#include <bits/stdc++.h>
using namespace std;

class Sth
{
	private:

	int data;

	public:

	Sth(int data){
		this->data = data;
		// this pointer helps us in such situations where we need to resolve these ambiguities
	}

};

//creating chainable functions of a class would use this pointer
class Calc
{
	private:

	int data {0};

	public:

	Calc& add(int val){data+=val;return *this;}
	Calc& sub(int val){data-=val;return *this;}
	Calc& mult(int val){data*=val;return *this;}

	void display(){
		cout<<"The value is "<<data<<endl;
	}

};

int main(){

	Calc obj{};

	obj.add(10).sub(5).mult(8);
	obj.display();

	return 0;
}