class Solution {
public:

    // house robber I space optimize solution 

    int robI(vector<int>& nums, int start, int end) {
        int n = nums.size();
        int prev = 0;
        int prev2 = 0;

        for(int i = start; i <= end; i++){
            int take = nums[i];
            if(i > 1){
                take+=prev2;
            }
            int notTake = 0 + prev;

            int curr = max(take, notTake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }


    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int case1 = robI(nums, 0, n-2);
        int case2 = robI(nums, 1, n-1);
        return max(case1, case2);
    }
};



