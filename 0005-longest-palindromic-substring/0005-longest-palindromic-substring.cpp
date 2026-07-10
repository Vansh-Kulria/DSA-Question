class Solution {
public:
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;   // palindrome length
    }

    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            int odd = expand(s, i, i);       // odd length
            int even = expand(s, i, i + 1); // even length

            int len = max(odd, even);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
