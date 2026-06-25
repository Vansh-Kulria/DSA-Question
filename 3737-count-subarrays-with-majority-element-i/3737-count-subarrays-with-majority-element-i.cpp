class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();

        for (int start = 0; start < n; start++) {
            int cnt = 0;

            for (int end = start; end < n; end++) {
                if (nums[end] == target) {
                    cnt++;
                }
                int len = end - start + 1;
                if (cnt * 2 > len) {
                    ans++;
                }
            }
        }
        return ans;
    }
};