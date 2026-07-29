// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {

//         int window = 1;
//         int n = nums.size();

//         while (window <= n) {

//             int start = 0;

//             while (start <= n - window) {

//                 int end = start + window - 1;

//                 if (accumulate(nums.begin() + start,
//                                nums.begin() + end + 1,
//                                0) >= target)
//                     return window;

//                 start++;
//             }

//             window++;
//         }

//         return 0;
//     }
// };

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int start = 0;
        int sum = 0;
        int ans = INT_MAX;

        for (int end = 0; end < nums.size(); end++) {

            sum += nums[end];
            
         while (sum >= target) {

                ans = min(ans, end - start + 1);

                sum -= nums[start];
                start++;
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};