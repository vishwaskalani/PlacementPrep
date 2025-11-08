
// 1 Jan 1900 was a Monday.
// Thirty days has September,
// April, June and November.
// All the rest have thirty-one,
// Saving February alone,
// Which has twenty-eight, rain or shine.
// And on leap years, twenty-nine.
// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <bits/stdc++.h>
using namespace std;

bool checkLeap(int year){
	if(year%400==0){
		return true;
	}
	else if(year%4==0 && year%100!=0){
		return true;
	}
	return false;
}


int countDays(int month,int year){
	if(month==2){
		if(checkLeap(year)){
			return 29;
		}
		else{
			return 28;
		}
	}
	else if (month==1 || month==3 || month==5 || month ==7 || month==8 || month==10 || month==12){
		return 31;
	}
	else{
		return 30;
	}
}



int main(){

	int countSunday = 0;

	// 1 jan 1900 is a monday so 1 jan 1901 will be Tuesday thus the first sunday will be 6 Jan 1901
	int total = 0;
	int ans =0;
	for(int year = 1901; year<=2000; year++){
		for(int month= 1; month<= 12; month++){
			int maxDays = countDays(month,year);
			if((total+maxDays)%7==5){
				ans++;
			}
			total+=maxDays;
		}
	}
	cout<<"The number of Sundays in the given period is : "<<ans<<endl;
	return 0;
}