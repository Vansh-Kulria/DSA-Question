class Solution {
public:
    bool checkPalindrom(string s, int start, int last) {
        while (start < last) {
            if (s[start] != s[last]) {
                return false;
            } else {
                start++;
                last--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int start = 0;
        int last = s.size() - 1;
        while (start < last) {
            if (s[start] != s[last]) {
                return checkPalindrom(s, start + 1, last) ||
                       checkPalindrom(s, start, last - 1);
            }
            start++;
            last--;
        }
        return true;
    }
};