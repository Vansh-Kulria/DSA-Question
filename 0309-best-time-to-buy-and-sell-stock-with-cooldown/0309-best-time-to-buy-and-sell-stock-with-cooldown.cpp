// class Solution {
// public:
//     int f(vector<int>& prices, int ind, int buy, int& n,
//           vector<vector<int>>& dp) {
//         // base case
//         if (ind >= n)
//             return 0;

//         if (dp[ind][buy] != -1)
//             return dp[ind][buy];
//         if (buy) {
//             return dp[ind][buy] =
//                        max(-prices[ind] + f(prices, ind + 1, 0, n, dp),
//                            0 + f(prices, ind + 1, 1, n, dp));
//         } else {
//             return dp[ind][buy] =
//                        max(prices[ind] + f(prices, ind + 2, 1, n, dp),
//                            0 + f(prices, ind + 1, 0, n, dp));
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return f(prices, 0, 1, n, dp);
//     }
// };




class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {

            // buy = 1
            dp[ind][1] = max(-prices[ind] + dp[ind + 1][0],
                              dp[ind + 1][1]);

            // buy = 0
            dp[ind][0] = max(prices[ind] + dp[ind + 2][1],
                              dp[ind + 1][0]);
        }

        return dp[0][1];
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