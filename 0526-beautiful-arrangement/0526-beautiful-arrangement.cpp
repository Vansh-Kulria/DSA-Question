class Solution {
public:
    int ans = 0;

    void solve(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans++;
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);

            int pos = index + 1;   // 1-based position

            if (nums[index] % pos == 0 || pos % nums[index] == 0) {
                solve(nums, index + 1);
            }

            swap(nums[index], nums[i]); // Backtrack
        }
    }

    int countArrangement(int n) {
        vector<int> nums;

        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        solve(nums, 0);

        return ans;
    }
};


// class Solution {
// public:

//     void solve(int pos,
//                int n,
//                vector<bool>& used,
//                int& ans) {

//         // All positions are filled
//         if (pos > n) {
//             ans++;
//             return;
//         }

//         // Try every number
//         for (int num = 1; num <= n; num++) {

//             if (used[num])
//                 continue;

//             // Check if num can be placed at position pos
//             if (num % pos == 0 || pos % num == 0) {

//                 used[num] = true;

//                 solve(pos + 1, n, used, ans);

//                 used[num] = false;      // Backtrack
//             }
//         }
//     }

//     int countArrangement(int n) {

//         vector<bool> used(n + 1, false);

//         int ans = 0;

//         solve(1, n, used, ans);

//         return ans;
//     }
// };