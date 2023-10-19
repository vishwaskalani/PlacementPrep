// A singleton class is a special type of class in object-oriented programming 
// which can have only one object or instance at a time. 
// In other words, we can instantiate only one instance of the singleton class. 
// The new variable also points to the initial instance created 
// if we attempt to instantiate the Singleton class after the first time. 

#include<bits/stdc++.h>
using namespace std;

class Singleton{

private:

	string name,loves;
	static Singleton* instancePtr;

	Singleton(){

	}

public:

	// copy operator deletion
	Singleton(const Singleton&obj) = delete;

	static Singleton* getInstance()
	{
		if(instancePtr==NULL){
			instancePtr = new Singleton();
			return instancePtr;
		}
		else{
			return instancePtr;
		}
	}

	void setValues(string name,string Loves){
		this->name = name;
		this->loves = Loves;
	}

	void print(){
		cout<<name<<" loves "<<loves<<endl;
	}

};

Singleton* Singleton ::instancePtr = NULL;

int main(){


	// we need to make the member function getInstance static because the constructor is private and 
	// we need to make an instance without making an object
	Singleton* Vishwas = Singleton ::getInstance(); 
   
	Vishwas->setValues("Vishwas","33"); 
	
	Vishwas ->print(); 
	
	cout << "Address of Vishwas: " << Vishwas << endl;
	
	cout << endl; 
	
	Singleton* Newgirl = Singleton ::getInstance(); 
	
	Newgirl->setValues("Vishwas","a number above 10 but below 18"); 
	
	Newgirl->print(); 
	
	cout << "Address of NewGirl: " << Newgirl << endl;

	return 0;
}