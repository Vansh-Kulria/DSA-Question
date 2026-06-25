class Solution {
  public:
    void solve(vector<int> &candidates, int target, int index,
               vector<int> &output, vector<vector<int>> &result) {

        if (target == 0) {
            result.push_back(output);
            return;
        }

        if (index >= candidates.size() || target < 0)
            return;

        // Include current element
        output.push_back(candidates[index]);
        solve(candidates, target - candidates[index], index + 1, output,
              result);

        output.pop_back();

        // Skip duplicates
        while (index + 1 < candidates.size() &&
               candidates[index] == candidates[index + 1]) {
            index++;
        }

        // Exclude current element
        solve(candidates, target, index + 1, output, result);
    }

 vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {

    sort(candidates.begin(), candidates.end());

    vector<vector<int>> result;
    vector<int> output;

    solve(candidates, target, 0, output, result);

    return result;
}
}
;