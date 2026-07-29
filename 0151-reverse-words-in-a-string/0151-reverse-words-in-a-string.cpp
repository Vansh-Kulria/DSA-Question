class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string res = "";
        int n = s.size() - 1;

        for (int i = 0; i <= n; i++) {
            string word = "";
            while (i <= n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());
            if (word.length() > 0) {

                    res += " " + word;
            }
        }

        return res.substr(1);
    }
};