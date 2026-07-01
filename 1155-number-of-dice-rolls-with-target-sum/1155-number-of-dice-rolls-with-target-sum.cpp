class Solution {
public:
  int MOD = 1e9 + 7;

  int numRollsToTarget(int d, int f, int target) {

    vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
    // base case
    dp[0][0] = 1;

    for(int dice = 1; dice <= d; dice++){
        for(int sum = 1; sum <= target; sum++){
            for(int face = 1; face <= f; face++){
                if((sum - face) >= 0){
                    dp[dice][sum] = (dp[dice][sum] + dp[dice-1][sum -face]) % MOD;
                }
            }
        }
    }
    return dp[d][target];
  }
};
