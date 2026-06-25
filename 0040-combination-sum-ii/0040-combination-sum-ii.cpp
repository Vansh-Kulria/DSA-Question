class Solution {
public:
    void solve(vector<int>& candidates,
               int target,
               int start,
               vector<int>& output,
               vector<vector<int>>& result) {

        if (target == 0) {
            result.push_back(output);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // No need to continue if target becomes negative
            if (candidates[i] > target)
                break;

            output.push_back(candidates[i]);

            solve(candidates,
                  target - candidates[i],
                  i + 1,
                  output,
                  result);

            output.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;
        vector<int> output;

        solve(candidates, target, 0, output, result);

        return result;
    }
};