// In this file we will be implementing a trading order book and matching engine.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

enum class Side { BUY, SELL };

struct Order {
	string id;
	Side side;
	ll price;
	ll quantity;
	uint64_t timestamp;

};

struct PriceLevel {

	list<Order> orders;
	ll totalQuantity;

};

class OrderBook {

	public:

	OrderBook(){
		now = 0;
	}

	void add_limit(const string& id,Side side,ll price,ll qty){
		if(qty<0){
			return;
		}
		Order o{id,side,price,qty,++now};
		if(side==Side::BUY){
			match(o,asks,bids,true);
		}
		else{
			match(o,asks,bids,false);
		}
		if(o.quantity>0){
			insert_remaining(o);
		}
	}

	private:

	map<ll,PriceLevel, greater<ll>> bids;
	map<ll,PriceLevel> asks;
	
	void match(Order &incoming,map<ll,PriceLevel> &oppBook, map<ll,PriceLevel,greater<ll>> &myBook,bool isBuy){
		// buy order implementation
		if(isBuy){

			auto it = asks.begin();
			while(incoming.quantity>0 && it!=asks.end() && it->first<=incoming.price){
				PriceLevel &pl = it->second;
				auto lit = pl.orders.begin();
				while(incoming.quantity>0 && lit != pl.orders.end()){
					Order &resting = *lit;
					ll tradeQuantity = min(incoming.quantity,resting.quantity);
					cout<<"TRADE "<<incoming.id<<" "<<resting.id<<" "<<it->first<<" "<<tradeQuantity<<"\n";
					incoming.quantity-=tradeQuantity;
					resting.quantity-=tradeQuantity;
					pl.totalQuantity-=tradeQuantity;
					if(resting.quantity==0){
						lit=pl.orders.erase(lit);
					}
					else{
						lit++;
					}
				}
				if(pl.orders.empty()){
					it = asks.erase(it);
				}
				else{
					it++;
				}
			}
		}
		// sell order implementation
		else{
			auto it = bids.begin();
			while(incoming.quantity>0 && it!=bids.end() && incoming.price<=it->first){
				PriceLevel &pl = it->second;
				auto lit = pl.orders.begin();
				while(incoming.quantity>0 && lit != pl.orders.end()){
					Order &resting = *lit;
					ll tradeQuantity = min(incoming.quantity,resting.quantity);
					cout<<"TRADE "<<resting.id<<" "<<incoming.id<<" "<<it->first<<" "<<tradeQuantity<<"\n";
					incoming.quantity-=tradeQuantity;
					resting.quantity-=tradeQuantity;
					pl.totalQuantity-=tradeQuantity;
					if(resting.quantity==0){
						lit=pl.orders.erase(lit);
					}
					else{
						lit++;
					}
				}
				if(pl.orders.empty()){
					it = bids.erase(it);
				}
				else{
					it++;
				}
			}
		}
	}

	void insert_remaining(Order& o){
		if(o.quantity<=0){
			return;
		}
		if(o.side==Side::BUY){
			// we need to store it in the bid store
			if(bids.find(o.price)==bids.end()){
				list<Order> newList = {o};
				bids[o.price] = PriceLevel{newList,o.quantity};
			}
			else{
				bids[o.price].orders.push_back(o);
				bids[o.price].totalQuantity+=o.quantity;
			}
		}
		else{
			// we need to store it in the ask store
			if(asks.find(o.price)==asks.end()){
				list<Order> newList = {o};
				asks[o.price] = PriceLevel{newList,o.quantity};
			}
			else{
				asks[o.price].orders.push_back(o);
				asks[o.price].totalQuantity+=o.quantity;
			}
		}
	}

	uint64_t now;


};

int main(){

	// makes the io faster	
	ios::sync_with_stdio(false);

	OrderBook ob;

	string cmd;

	cout<<"------STARTING THE TRADING SYSTEM-------"<<"\n";

	while(cin>>cmd){
		if(cmd=="N"){
			string id;
			char side;
			ll p;
			ll q;
			cin>>id>>side>>p>>q;
			Side s = (side=='B') ? Side::BUY : Side::SELL;
			ob.add_limit(id,s,p,q);
		}
		else{
			cout<<"UNKNOWN COMMAND "<<cmd<<"\n";
			string rest;
			getline(cin,rest);
		}
	}
	return 0;
}