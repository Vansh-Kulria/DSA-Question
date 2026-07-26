// class Solution {
// public:
//     int f(vector<int>& prices, int ind, int cup, int buy, int& n,
//           vector<vector<vector<int>>>& dp) {
//         // base case
//         if (ind == n)
//             return 0;
//         if (cup == 0)
//             return 0;

//         if (dp[ind][buy][cup] != -1)
//             return dp[ind][buy][cup];
//         if (buy && cup) {
//             return dp[ind][buy][cup] =
//                        max(-prices[ind] + f(prices, ind + 1, cup, 0, n, dp),
//                            0 + f(prices, ind + 1, cup, buy, n, dp));
//         } else {
//             return dp[ind][buy][cup] =
//                        max(prices[ind] + f(prices, ind + 1, cup - 1, 1, n,
//                        dp),
//                            0 + f(prices, ind + 1, cup, buy, n, dp));
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(
//             n, vector<vector<int>>(2, vector<int>(3, -1)));
//         return f(prices, 0, 2, 1, n, dp);
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for (int ind = n - 1; ind >= 0; ind--) {
            dp[ind][0][0] = dp[ind][1][0] = 0;
        }

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int cap = 1; cap <= 2; cap++) {
                // buy = 1
                dp[ind][1][cap] = max(-prices[ind] + dp[ind + 1][0][cap],
                                      dp[ind + 1][1][cap]);

                // buy = 0
                dp[ind][0][cap] = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                      dp[ind + 1][0][cap]);
            }
        }
        return dp[0][1][2];
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {

//         int n = prices.size();

//         vector<int> ahead(2, 0), curr(2, 0);

//         for (int ind = n - 1; ind >= 0; ind--) {

//             curr[1] = max(-prices[ind] + ahead[0],
//                           ahead[1]);

//             curr[0] = max(prices[ind] + ahead[1],
//                           ahead[0]);

//             ahead = curr;
//         }

//         return ahead[1];
//     }
// };