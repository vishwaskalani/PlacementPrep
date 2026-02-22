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

struct OrderLocator{
		Side side;
		ll price;
		list<Order>::iterator listIt;
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

	bool cancelOrder(const string &id){
		auto it = orderMap.find(id);
		if(it==orderMap.end()){
			return false;
		}
		OrderLocator ol = it->second;
		if(ol.side==Side::BUY){
			bids[ol.price].totalQuantity-=ol.listIt->quantity;
			bids[ol.price].orders.erase(ol.listIt);
			if(bids[ol.price].orders.empty()){
				bids.erase(ol.price);
			}
		}
		else{
			asks[ol.price].totalQuantity-=ol.listIt->quantity;
			asks[ol.price].orders.erase(ol.listIt);
			if(asks[ol.price].orders.empty()){
				asks.erase(ol.price);
			}
		}
		orderMap.erase(id);
		return true;
	}

	void modifyOrder(const string &id,ll np,ll nq){
		try{
			Side s = getOrderSide(id);
			bool cancelResult = cancelOrder(id);
			if(!cancelResult){
				cout<<"Modification of "<<id<<" failed during cancellation"<<"\n";
			}
			else{
				add_limit(id,s,np,nq);
				cout<<"Modification of "<<id<<" success"<<"\n";
			}
		}
		catch(runtime_error &e){
			cout<<"Modification of "<<id<<" failed: Order not found"<<"\n";
		}
	}

	void printBook(){
		cout<<"-----ORDER BOOK-----"<<"\n";
		cout<<"BIDS:"<<"\n";
		for(auto &b: bids){
			cout<<"Price: "<<b.first<<" Total Quantity: "<<b.second.totalQuantity<<"\n";
		}
		cout<<"ASKS:"<<"\n";
		for(auto &a: asks){
			cout<<"Price: "<<a.first<<" Total Quantity: "<<a.second.totalQuantity<<"\n";
		}
		cout<<"--------------------"<<"\n";
	}

	
	private:

	uint64_t now;

	map<ll,PriceLevel, greater<ll>> bids; // highest bid first
	map<ll,PriceLevel> asks;

	map<string,OrderLocator> orderMap;
	
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
						auto omIt = orderMap.find(resting.id);
                        if (omIt != orderMap.end()) orderMap.erase(omIt);
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
						auto omIt = orderMap.find(resting.id);
                        if (omIt != orderMap.end()) orderMap.erase(omIt);
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
				OrderLocator ol{Side::BUY,o.price,bids[o.price].orders.begin()};
				orderMap[o.id] = ol;
			}
			else{
				OrderLocator ol{Side::BUY,o.price,bids[o.price].orders.end()};
				orderMap[o.id] = ol;
				bids[o.price].orders.push_back(o);
				bids[o.price].totalQuantity+=o.quantity;
			}
		}
		else{
			// we need to store it in the ask store
			if(asks.find(o.price)==asks.end()){
				list<Order> newList = {o};
				asks[o.price] = PriceLevel{newList,o.quantity};
				OrderLocator ol{Side::SELL,o.price,asks[o.price].orders.begin()};
				orderMap[o.id] = ol;
			}
			else{
				OrderLocator ol{Side::SELL,o.price,asks[o.price].orders.end()};
				orderMap[o.id] = ol;
				asks[o.price].orders.push_back(o);
				asks[o.price].totalQuantity+=o.quantity;
			}
		}
	}

	Side getOrderSide(const string &id){
		auto it = orderMap.find(id);
		if(it==orderMap.end()){
			throw runtime_error("Order not found");
		}
		return it->second.side;
	}


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
		else if(cmd=="C"){
			string id;
			cin>>id;
			bool cancelResult = ob.cancelOrder(id);
			if(!cancelResult){
				cout<<"Cancellation of "<<id<<" failed"<<"\n";
			}
			else{
				cout<<"Cancellation of "<<id<<" success"<<"\n";
			}
		}
		// modify the order price or q
		else if(cmd=="M"){
			string id;
			cin>>id;
			ll np;
			ll nq;
			cin>>np>>nq;
			ob.modifyOrder(id,np,nq);
		}
		else if(cmd=="P"){
			ob.printBook();
		}
		else{
			cout<<"UNKNOWN COMMAND "<<cmd<<"\n";
			string rest;
			getline(cin,rest);
		}
	}
	return 0;
}