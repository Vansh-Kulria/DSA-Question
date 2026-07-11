class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev2 = cost[0];
        int prev = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev2, prev);

            prev2 = prev;
            prev = curr;
        }

        return min(prev,prev2);
    }
};