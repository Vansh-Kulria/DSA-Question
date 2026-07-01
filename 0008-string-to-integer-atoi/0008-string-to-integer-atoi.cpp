class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long num = 0;
        int n = s.length();
        bool isneg = false;

        while (i < n && s[i] == ' ') {
            i++;
        }

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                isneg = true;
            }
            i++;
        }

        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');

            if (!isneg && num > INT_MAX)
                return INT_MAX;

            if (isneg && -num < INT_MIN)
                return INT_MIN;

            i++;
        }
        if (isneg)
            num = -num;

        return (int)num;
    }
};