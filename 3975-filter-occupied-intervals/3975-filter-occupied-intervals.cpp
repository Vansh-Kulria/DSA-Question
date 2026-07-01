class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        if (occupiedIntervals.empty())
            return {};

        // Step 1: Sort
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        // Step 2: Merge overlapping and touching intervals
        vector<vector<int>> merged;

        for (auto &interval : occupiedIntervals) {

            if (merged.empty() ||
                interval[0] > merged.back()[1] + 1) {

                merged.push_back(interval);
            }
            else {
                merged.back()[1] =
                    max(merged.back()[1], interval[1]);
            }
        }

        // Step 3: Remove free interval
        vector<vector<int>> ans;

        for (auto &interval : merged) {

            int L = interval[0];
            int R = interval[1];

            // No overlap
            if (R < freeStart || L > freeEnd) {
                ans.push_back({L, R});
            }
            else {

                // Left remaining part
                if (L < freeStart) {
                    ans.push_back({L, freeStart - 1});
                }

                // Right remaining part
                if (R > freeEnd) {
                    ans.push_back({freeEnd + 1, R});
                }
            }
        }

        return ans;
    
    }
};