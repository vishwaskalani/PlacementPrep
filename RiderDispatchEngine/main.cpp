#include <bits/stdc++.h>
using namespace std;
using ll = long long;


struct Driver{
	string id;
	float x;
	float y;
};

struct Rider{
	string id;
	float x;
	float y;
};


class RideEngine{

	public:

	RideEngine(){}

	void assign(const string &id,float xord,float yord){

		float minDistance = 1e9;
		string bestDriver = "NONE";
		Rider rd = Rider{id,xord,yord};
		for(auto avld : avlDriverIds){
			float currDist = findDistance(driverDetails[avld],rd);
			if(currDist<minDistance){
				minDistance = currDist;
				bestDriver = avld;
			}
		}
		if(bestDriver=="NONE"){
			cout<<"NO_DRIVERS_AVAILABLE"<<"\n";
		}
		else{
			cout<<"RIDE "<<id<<" -> "<<"DRIVER "<<bestDriver<<" DIST "<<minDistance<<"\n";
			avlDriverIds.erase(bestDriver);
			navlDriverIds.insert(bestDriver);
		}

	}

	void addDriver(const string &id,float xord,float yord){

		Driver d = Driver{id,xord,yord};
		driverDetails[id]=d;
		avlDriverIds.insert(id);

	}

	void completeRide(const string &id){
		navlDriverIds.erase(id);
		avlDriverIds.insert(id);
	}

	private:

	set<string> avlDriverIds;
	set<string> navlDriverIds;
	map<string,Driver> driverDetails;

	float findDistance(Driver &d,Rider &r){
		return abs(d.x-r.x)+abs(d.y-r.y);
	}

};

int main(){

	ios::sync_with_stdio(false);

	RideEngine rd;

	string cmd;
	while(cin>>cmd){

		if(cmd=="DRIVER"){
			string id;
			float x,y;
			cin>>id>>x>>y;
			rd.addDriver(id,x,y);
		}
		else if (cmd=="RIDE"){
			string id;
			float x,y;
			cin>>id>>x>>y;
			rd.assign(id,x,y);

		}
		else if (cmd=="COMPLETE"){
			string id;
			cin>>id;
			rd.completeRide(id);
		}

	}
	
	return 0;
}