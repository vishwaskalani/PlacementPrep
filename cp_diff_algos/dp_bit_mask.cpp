// Let there be N workers and N jobs. 
// Any worker can be assigned to perform any job, 
// incurring some cost that may vary depending on the work-job assignment. 
// It is required to perform all jobs by assigning exactly one worker 
// to each job and exactly one job to each agent in such a way that 
// the total cost of the assignment is minimized.
#include<bits/stdc++.h>
using namespace std;

int cost[21][21] = {};
int dp[21][1<<21] = {};

// this is top down dynamic programming
int solve(int j,int mask,int n){
	if(j==n){
		return 0;
	}
	else if(dp[j][mask]!=-1){
		return dp[j][mask];
	}
	else{
		int answer = INT_MAX;
		for(int i=0; i<n; i++){
			// this checks if the ith person is available or not
			if(mask&(1<<i)){
				answer = min(answer,cost[i][j]+solve(j+1,mask^(1<<i),n));
			}
		}
		return dp[j][mask]=answer;
	}
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n; i++){
		for(int j=0; j<n; j++){
			cin>>cost[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,(1<<n)-1,n)<<endl;
	return 0;
}
