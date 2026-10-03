

// class Solution {
// public:
//     int longestValidParentheses(string s) {

//         stack<int> st;
//         st.push(-1);

//         int ans = 0;

//         for(int i = 0; i < s.size(); i++) {

//             if(s[i] == '(') {
//                 st.push(i);
//             }
//             else {

//                 st.pop();

//                 if(st.empty()) {
//                     st.push(i);
//                 }
//                 else {
//                     ans = max(ans, i - st.top());
//                 }
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int longestValidParentheses(string s) {

        int n = s.size();
        int ans = 0;

        // Left -> Right
        int open = 0, close = 0;

        for (int i = 0; i < n; i++) {

            if (s[i] == '(')
                open++;
            else
                close++;

            // Too many ')' -> this part can never be valid
            if (close > open) {
                open = 0;
                close = 0;
            }

            // Valid substring
            if (open == close) {
                int current = open + close;
                ans = max(ans, current);
            }
        }

        // Right -> Left
        open = 0;
        close = 0;

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '(')
                open++;
            else
                close++;

            // Too many '(' when looking from right
            if (open > close) {
                open = 0;
                close = 0;
            }

            // Valid substring
            if (open == close) {
                int current = open + close;
                ans = max(ans, current);
            }
        }

        return ans;
    }
};