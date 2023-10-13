#include <bits/stdc++.h> 
using namespace std;
struct Res{
	int maxsum;
	int lb;
	int rb;
	int ub;
	int llb;
	Res(){
		maxsum = INT_MIN;
		lb = -1;
		rb = -1;
		ub = -1;
		llb = -1;
	}
};

struct KadaneRes{
	int maxsum;
	int start;
	int end;
	KadaneRes(int v1,int v2,int v3){
		maxsum = v1;
		start = v2;
		end = v3;
	}
};

KadaneRes kadane(vector<int>& arr){
	int maxi = 0;
	int maxstart = -1;
	int maxend = -1;
	int curr_start = 0;
	int max_sofar = 0;
	int max_elem = INT_MIN;
	int max_ind = -1;
	for(int i=0; i<arr.size(); i++){
		max_sofar+=arr[i];
		if(max_sofar<0){
			max_sofar = 0;
			curr_start = i+1;
		}
		if(maxi<max_sofar){
			maxstart = curr_start;
			maxend = i;
			maxi = max_sofar;
		}
		if(max_elem<arr[i]){
			max_elem = arr[i];
			max_ind = i;
		}
	}
	if(maxstart==-1){
		return KadaneRes(max_elem,max_ind,max_ind);
	}
	return KadaneRes(maxi,maxstart,maxend);
}


int maxSumRectangle(vector<vector<int>>& matrix, int n, int m)
{
	// write your code here
	vector<int> temp(n,0);
	Res res;
	for(int left = 0;left<m; left++){
		for(int i=0; i<n; i++){
			temp[i] = 0;
		}
		for(int right = left; right<m; right++){
			for(int i=0; i<n; i++){
				temp[i] += matrix[i][right];
			}
			KadaneRes kres = kadane(temp);
			if(kres.maxsum>res.maxsum){
				res.maxsum = kres.maxsum;
				res.lb = left;
				res.rb = right;
				res.ub = kres.start;
				res.lb = kres.end;
			} 
		}
	}
	return res.maxsum;
}

int main(){
	cout<<"Function for finding max sum rectangle";
	return 0;
}