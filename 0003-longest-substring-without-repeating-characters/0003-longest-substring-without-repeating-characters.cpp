class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> hash(256, -1);

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // If character has already appeared inside the current window
            if (hash[s[right]] != -1 && hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }

            // Update the last seen index
            hash[s[right]] = right;

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};