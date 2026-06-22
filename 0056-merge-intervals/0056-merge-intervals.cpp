class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> output;

        for (const auto& interval : intervals) {
            if (output.empty() || interval[0] > output.back()[1]) {
                output.push_back(interval);
            } else {
                output.back()[1] = max(output.back()[1], interval[1]);
            }
        }

        return output;
    }
};