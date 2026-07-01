class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int n = num.length() - 1;
        int start = 0;
        while (start <= n) {

            if (num[start] != num[n]) {
                return false;
            } else {
                start++;
                n--;
            }
        }
        return true;
    }
};