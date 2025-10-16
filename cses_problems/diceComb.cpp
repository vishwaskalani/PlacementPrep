#include <bits/stdc++.h>
using namespace std;

int diceComb(int n){
	const int mod = 1e9+7;
	vector<int> dp(n+1,0);
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=6;j++){
			if(i-j>=0){
				dp[i] = (dp[i] + dp[i-j])%mod;
			}
		}
	}
	return dp[n];

}

int main(){

	int n;
	cin>>n;
	cout<<diceComb(n)<<endl;

	return 0;
}