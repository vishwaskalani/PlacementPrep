#include <bits/stdc++.h>
using namespace std;

struct FenwickTree{
	vector<int> bit;
	int n;

	FenwickTree(int n){
		this->n = n;
		bit.assign(n,0);
	}

	FenwickTree(vector<int> const &a): FenwickTree(a.size()) {
		for(int i=0; i<a.size(); i++){
			add(i,a[i]);
		}
	}

	int sum(int r){
		int ret = 0;
		while (r >= 0) {
			ret += bit[r];
			r = (r & (r + 1)) - 1;
		}
		return ret;
	}

	int sum(int l,int r){
		return sum(r)-sum(l-1);
	}

	void add(int idx,int delta){
		while(idx<n){
			bit[idx] += delta;
			idx = idx | (idx+1);
		}
	}

};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    FenwickTree fenwickTree(arr);

    cout << "Prefix sum up to index 3: " << fenwickTree.sum(3) << endl;

    cout << "Sum in range [1, 3]: " << fenwickTree.sum(1, 3) << endl;

    fenwickTree.add(2, 2);

    cout << "Prefix sum up to index 3 after update: " << fenwickTree.sum(3) << endl;

    return 0;
}
