class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for (int ind = 0; ind <= n - 1; ind++) {
            for (int prev = 0; prev <= ind - 1; prev++) {
                if (nums[ind] > nums[prev] && dp[prev] + 1 > dp[ind]) {
                    // inherit
                    dp[ind] = dp[prev] + 1;
                    cnt[ind] = cnt[prev];
                }

                else if (nums[ind] > nums[prev] && dp[prev] + 1 == dp[ind]) {
                    // increase the count
                    cnt[ind] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[ind]);
        }

        int nos = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi)
                nos += cnt[i];
        }
        return nos;
    }
};