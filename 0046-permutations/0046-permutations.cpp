class Solution {
public:
    void solve(vector<int>& nums, int index,vector<vector<int>>&ans, vector<int> &output){
        // base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        // 1 case m solve krunga baaki recursion 
        for (int j = index; j < nums.size(); j++){
            swap(nums[index],nums[j]);
            output.push_back(nums[index]);
            solve(nums, index+1, ans,output);
            swap(nums[index],nums[j]);
            output.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, index, ans, output);
        return ans;
    }
};