class Solution {
public:
void solve(vector<int>& candidates, int target, int index, vector<vector<int>>& result, vector<int> &output){
     if(target == 0){
        result.push_back(output);
        return;
    }

    if(index >= candidates.size()){
        return;
    }

    // include
    if(candidates[index] <= target){

        output.push_back(candidates[index]);

        solve(candidates,
              target - candidates[index],
              index,
              result,
              output);

        output.pop_back();    // backtrack
    }

    // exclude
    solve(candidates,
          target,
          index + 1,
          result,
          output);
}

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index = 0;
        vector<vector<int>> result;
        vector<int> output;
        solve(candidates, target, index, result, output);
        return result;
        
    }
};