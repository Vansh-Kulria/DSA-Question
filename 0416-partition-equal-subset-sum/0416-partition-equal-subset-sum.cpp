class Solution {
public:
bool solve(vector<int>& nums, int target , int index, vector<vector<int>>& dp){
    if(target < 0 || index == nums.size()) return false;
    if(target == 0) return true;
    if(dp[index][target] != -1 ) return dp[index][target];
    bool inc = solve(nums,target-nums[index], index +1, dp);
    bool exc = solve(nums , target, index+1,dp);

    return dp[index][target] = inc || exc;
}
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(sum & 1){
            return false;
        }
        int target = sum >> 1;
        vector<vector<int>>dp(n, vector<int>(target+1,-1));
        return solve(nums, target , 0 ,dp);
     }
};