#include <bits/stdc++.h>
using namespace std;

void readFile(string filename){
	ifstream fileread(filename);
	string text;
	while(getline(fileread,text)){
		cout<<text<<"\n";
	}
	fileread.close();
}

void writeToFile(string filename, string text){
	ofstream filewrite(filename);
	filewrite<<text;
	filewrite.close();
}

int main(){
	readFile("example.txt");
	writeToFile("example1.txt","Try hard, don't worry or think of consequences \n You can do it !!");
	return 0;
}