class Solution {
public:
int f(int amount, vector<int> &coins, vector<vector<int>> &dp,int n){
    // base case
    if(n == 0){
        if(amount % coins[0] != 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    if(amount == 0){
        return 1;
    }


    if(dp[n][amount] != -1) return dp[n][amount];

    int take = 0;
    if(amount >= coins[n]){
    take = f(amount - coins[n],coins, dp, n);
    }
    int not_take = 0 + f(amount,coins,dp,n-1);

    return dp[n][amount] = take + not_take;
}
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return f(amount,coins,dp,n-1);
    }
};