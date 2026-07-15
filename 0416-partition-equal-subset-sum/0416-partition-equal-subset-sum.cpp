// class Solution {
// public:
//     bool solve(vector<int>& nums, int target, int index,
//                vector<vector<int>>& dp) {
//         if (target == 0)
//             return true;

//         if (index == nums.size())
//             return false;
//         if (dp[index][target] != -1)
//             return dp[index][target];
//         bool inc = solve(nums, target - nums[index], index + 1, dp);
//         bool exc = solve(nums, target, index + 1, dp);

//         return dp[index][target] = inc || exc;
//     }
//     bool canPartition(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         int n = nums.size();
//         if (sum & 1) {
//             return false;
//         }
//         int target = sum >> 1;
//         vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//         return solve(nums, target, 0, dp);
//     }
// };



// tabulation method
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2)
            return false;

        int target = sum / 2;
        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base case: target = 0
        for(int i = 0; i <= n; i++)
            dp[i][0] = true;

        // Fill table
        for(int index = n - 1; index >= 0; index--) {

            for(int t = 1; t <= target; t++) {

                bool notTake = dp[index + 1][t];

                bool take = false;

                if(t >= nums[index])
                    take = dp[index + 1][t - nums[index]];

                dp[index][t] = take || notTake;
            }
        }

        return dp[0][target];
    }
};