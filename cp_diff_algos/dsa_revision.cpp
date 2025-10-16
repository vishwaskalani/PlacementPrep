#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subsetSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));

		// dp[i][j] represents whether a sum j is possible with the first i elements
        
        // TODO: Base case - sum 0 is always possible (empty subset)
		for(int i = 0; i <= n; i++) {
			dp[i][0] = true;
		}

        for(int i = 1; i <= n; i++) {
            for(int sum = 0; sum <= target; sum++) {
                bool notPick = dp[i-1][sum];
                bool pick = false;
                if(sum >= nums[i-1]) {
                    // TODO: If we can pick current number
					pick = dp[i-1][sum - nums[i-1]];
                }
                // TODO: Update dp[i][sum]
				dp[i][sum] = pick || notPick;
            }
        }
        
        return dp[n][target];
    }
};



int main(){


	return 0;
}