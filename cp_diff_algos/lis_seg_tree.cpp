#include <bits/stdc++.h>
using namespace std;

class Seg{
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
			seg[node] = max(seg[2*node+1],seg[2*node+2]);
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
			seg[node] = max(seg[2*node+1],seg[2*node+2]);
		}
	}

	int query_tree(int node,int l,int r,int lq,int rq){
		if(l>=lq && r<=rq){
			return seg[node];
		}
		else if(lq>r || rq<l){
			return 0;
		}
		else{
			int mid = (l+r)/2;
			int ls = query_tree(2*node+1,l,mid,lq,rq);
			int rs = query_tree(2*node+2,mid+1,r,lq,rq);
			return max(ls,rs);
		}
	}

public:
	Seg(vector<int>& nums){
		n = nums.size();
		seg.resize(4*n,0);
		build_tree(nums,0,0,n-1);
	}

	void update(int index,int val){
		update_tree(0,0,n-1,index,val);
	}
	int maxRange(int l,int r){
		return query_tree(0,0,n-1,l,r);
	}
};


int main(){
	int n = 8;
	vector<int> initial(n);
	Seg Segtree(initial);
	vector<int> arr = {0,8,3,1,6,4,2,9};
	vector<pair<int,int>> seq;
	for(int i=0; i<n; i++){
		seq.push_back({arr[i],i});
	}
	vector<pair<int,int>> sorted = seq;
	sort(sorted.begin(),sorted.end());
	map<int,int> mp;
	for(int i=0; i<n; i++){
		mp[sorted[i].second] = i;
	}
	int ans = 0;
	for(int i=0; i<n; i++){
		int ind = mp[i];
		int max_len = Segtree.maxRange(0,ind);
		Segtree.update(ind,max_len+1);
		ans = max(ans,max_len+1);
	}
	cout<<"Length of LIS is "<<ans<<endl;
	return 0;
}