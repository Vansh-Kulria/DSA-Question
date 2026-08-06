class Solution {
public:
    bool compare(string& s1, string& s2) {

        if (s1.size() != s2.size() + 1)
            return false;

        int first = 0;
        int second = 0;

        while (first < s1.size()) {

            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }

        return second == s2.size();
    }

    static bool comp(string& a, string& b) { return a.size() < b.size(); }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), comp);

        int n = words.size();

        vector<int> dp(n, 1);

        int maxi = 1;

        for (int i = 0; i < n; i++) {

            for (int prev = 0; prev < i; prev++) {

                if (compare(words[i], words[prev]) && dp[prev] + 1 > dp[i]) {

                    dp[i] = dp[prev] + 1;
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};