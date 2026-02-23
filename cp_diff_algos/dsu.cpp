#include <bits/stdc++.h>
using namespace std;

class DSU {

	private:

	vector<int> parent,rank;

	public:

	DSU(int n){
		parent.resize(n);
		rank.resize(n, 0);
		for(int i=0; i<n; i++){
			parent[i] = i;
		}
	}

	int find(int x) {
		if(parent[x] != x)
			parent[x] = find(parent[x]);  // Path compression
		return parent[x];
	}

	
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py]) {
            parent[px] = py;
        } else if(rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }

};

int main(){

	int n = 5;
	DSU dsu(n);
	dsu.unite(0,2);
	dsu.unite(4,2);
	dsu.unite(3,1);

	// check if 0 and 4 are friends
	if(dsu.find(0)==dsu.find(4)){
		cout<<"0 and 4 are friends"<<"\n";
	}
	else{
		cout<<"No, they are not friends"<<"\n";
	}


	return 0;
}