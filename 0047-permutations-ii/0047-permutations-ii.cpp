class Solution {
public:

    void solve(vector<int>& nums, int index,
               vector<vector<int>>& ans) {

        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int j = index; j < nums.size(); j++) {

            if (used.count(nums[j]))
                continue;

            used.insert(nums[j]);

            swap(nums[index], nums[j]);

            solve(nums, index + 1, ans);

            swap(nums[index], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        vector<vector<int>> ans;

        solve(nums, 0, ans);

        return ans;
    }
};