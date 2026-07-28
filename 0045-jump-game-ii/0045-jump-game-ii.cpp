class Solution {
public:
    int f( vector<int>& nums, int index, int & n,vector<int>&dp){
    //  base case   // 
    if(index >= n-1){
        return 0;
    }

    if(dp[index] != -1) return dp[index];
    int ans = 1e8;
    for(int jump = 1; jump <= nums[index]; jump++) {
        ans = min(ans, 1 + f(nums,index+jump,n,dp));
    }

    return dp[index] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(nums,0,n,dp);
    }
};