class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> mp = {
            {"I",1}, {"IV",4}, {"V",5}, {"IX",9},
            {"X",10}, {"XL",40}, {"L",50}, {"XC",90},
            {"C",100}, {"CD",400}, {"D",500},
            {"CM",900}, {"M",1000}
        };

        int ans = 0;

        for (int i = s.length() - 1; i >= 0; ) {
            string curr(1, s[i]);

            if (i > 0) {
                string prev(1, s[i - 1]);

                if (mp[curr] > mp[prev]) {
                    string combined;
                    combined.push_back(s[i - 1]);
                    combined.push_back(s[i]);

                    ans += mp[combined];
                    i -= 2;
                    continue;
                }
            }

            ans += mp[curr];
            i--;
        }

        return ans;
    }
};