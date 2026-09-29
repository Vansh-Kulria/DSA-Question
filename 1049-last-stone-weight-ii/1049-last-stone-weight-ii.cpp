class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totsum = 0;
        for (int i : stones) {
            totsum += i;
        }
        int n = stones.size();
        int target = totsum;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base cases
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        if (stones[0] <= target) {
            dp[0][stones[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {

                bool notTake = dp[i - 1][j];

                bool take = false;
                if (stones[i] <= j) {
                    take = dp[i - 1][j - stones[i]];
                }

                dp[i][j] = take || notTake;
            }
        }

        int mini = 1e9;
        for(int s1 = 0; s1 <= totsum/2; s1++){
            if(dp[n-1][s1] == true){
                int s2 = totsum-s1;
                mini = min(mini, abs(s1-s2));
            }
        }

        return mini;
    }
};