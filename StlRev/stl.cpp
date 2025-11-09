#include <bits/stdc++.h>
using namespace std;

struct Node{
	int a;
	int b;
	int c;
};

// A custom comparator that overloads the comparison operator
struct CustomComp{
	bool operator()(Node n1,Node n2){
		if(n1.a>n2.a){
			return true;
		}
		else if (n1.a==n2.a && n1.b>n2.b){
			return true;
		}
		else if(n1.a==n2.a && n1.b==n2.b && n1.c>n2.c){
			return true;
		}
		else{
			return false;
		}
	}
};

void unorderedSet(){

	unordered_set<int> s;
	for(int i=0; i<10;i++){
		s.insert(i);
	}
	s.insert(1);
	s.insert(-1);
	// unordered set removed duplicates but offers no ordering on the elements
	cout<<"Elements in unordered set are :";
	for(auto it = s.begin(); it!=s.end();it++){
		cout<< *it<<" ";
	}
	cout<<"\n";
}

void multiSet(){
	//associative container just like a set, only difference is that it can store duplicates into it
	multiset<int> ms;
	for(int i=0; i<10; i++){
		ms.insert(i);
	}
	ms.insert(0);
	cout<<"Elements in unordered set are :";
	for(auto it = ms.begin(); it!=ms.end();it++){
		cout<< *it<<" ";
	}
	cout<<"\n";
}

// in the similar way there is an unordered multiset as well

int main(){

	unorderedSet();

	multiSet();

	// using a custom comparator for priority q in C++
	priority_queue<Node,vector<Node>,CustomComp> pq;

	Node n1{1,2,3};
	Node n2{2,2,3};
	Node n3{1,3,3};
	Node n4{1,2,4};

	pq.push(n1);
	pq.push(n2);
	pq.push(n3);
	pq.push(n4);

	// print the order of elements in the pq now
	while(!pq.empty()){
		Node topElement = pq.top();
		cout<<topElement.a<<" "<<topElement.b<<" "<<topElement.c<<"\n";
		pq.pop();
	}
	
	return 0;
}