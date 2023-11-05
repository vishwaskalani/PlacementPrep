#include <bits/stdc++.h>
using namespace std;

class NumArray{
private:
	int n;
	vector<int> seg;
	void build_tree(vector<int>& nums,int node,int l,int r){
		if(l==r){
			seg[node] = nums[l];
			return;
		}
		else{
			int mid = (l+r)/2;
			build_tree(nums,2*node+1,l,mid);
			build_tree(nums,2*node+2,mid+1,r);
			seg[node] = seg[2*node+1]+seg[2*node+2];
		}

	}

	void update_tree(int node,int l,int r,int ind,int val){
		if(l==r){
			seg[node] = val;
		}
		else{
			int mid = (l+r)/2;
			if(ind<=mid){
				update_tree(2*node+1,l,mid,ind,val);
			}
			else{
				update_tree(2*node+2,mid+1,r,ind,val);
			}
			seg[node] = seg[2*node+1]+seg[2*node+2];
		}
	}

	int query_tree(int node,int l,int r,int lq,int rq){
		if(lq>=l && rq<=r){
			return seg[node];
		}
		else if(lq>r || rq<l){
			return 0;
		}
		else{
			int mid = (l+r)/2;
			int ls = query_tree(2*node+1,l,mid,lq,rq);
			int rs = query_tree(2*node+2,mid+1,r,lq,rq);
			return ls+rs;
		}
	}

public:
	NumArray(vector<int>& nums){
		n = nums.size();
		seg.resize(4*n,0);
		build_tree(nums,0,0,n-1);
	}

	void update(int index,int val){
		update_tree(0,0,n-1,index,val);
	}
	int sumRange(int l,int r){
		return query_tree(0,0,n-1,l,r);
	}
};


int main(){

	return 0;
}