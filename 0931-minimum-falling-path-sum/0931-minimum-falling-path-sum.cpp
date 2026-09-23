class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // First row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int up = dp[i - 1][j];

                int left_up = INT_MAX;
                if (j > 0)
                    left_up = dp[i - 1][j - 1];

                int right_up = INT_MAX;
                if (j < n - 1)
                    right_up = dp[i - 1][j + 1];

                dp[i][j] = matrix[i][j] + min({up, left_up, right_up});
            }
        }

        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};