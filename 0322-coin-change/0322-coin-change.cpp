class Solution {
public:
    // int f(int ind, vector<int>& coins, int target, vector<vector<int>>& dp) {

    //     if (target == 0)
    //         return 0;

    //     if (ind == 0) {
    //         if (target % coins[0] == 0)
    //             return target / coins[0];
    //         return 1e9;
    //     }
    //     if (dp[ind][target] != -1)
    //         return dp[ind][target];
    //     int notTake = f(ind - 1, coins, target, dp);

    //     int take = 1e9;

    //     if (coins[ind] <= target) {
    //         take = 1 + f(ind, coins, target - coins[ind], dp);
    //     }

    //     return dp[ind][target] = min(take, notTake);
    // }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        int ans = 0;

        // base case
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else {
                dp[0][i] = 1e9;
            }
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 1; tar <= amount; tar++) {
                int notTake = dp[ind - 1][tar];

                int take = 1e9;
                if (coins[ind] <= tar) {
                    take = 1 + dp[ind][tar - coins[ind]];
                }

                dp[ind][tar] = min(take, notTake);
            }
        }

        if (dp[n - 1][amount] == 1e9) {
            return -1;
        } else {
            return dp[n - 1][amount];
        }
    }
};