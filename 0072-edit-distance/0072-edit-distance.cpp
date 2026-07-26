// class Solution {
// public:
//     int f(string& word1, string& word2, int i, int j, vector<vector<int>>&
//     dp) {
//         // base case
//         if (i < 0)                           // for 1 base index i == 0
//             return j + 1;                    // for 1 base index return j;
//         if (j < 0)                           // for 1 base index j == 0;
//             return i + 1;                    // for 1 base index return i;

//         if (dp[i][j] != -1)
//             return dp[i][j];

//         if (word1[i] == word2[j]) {          // 1 base index -> word1[i-1] ==
//         word2[j-1];
//             return dp[i][j] = f(word1, word2, i - 1, j - 1, dp);
//         }

//         return dp[i][j] = 1 + min(f(word1, word2, i - 1, j - 1, dp),
//                            min(f(word1, word2, i - 1, j, dp),
//                                f(word1, word2, i, j - 1, dp)));
//     }
//     int minDistance(string word1, string word2) {
//         int n = word1.size();
//         int m = word2.size();

//         vector<vector<int>> dp(n, vector<int>(m, -1));      // for 1 base
//         index dp[n+1][m+1]; return f(word1, word2, n - 1, m - 1, dp);
//     }
// };

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // base case
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1],
                                       min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[n][m];
    }
};