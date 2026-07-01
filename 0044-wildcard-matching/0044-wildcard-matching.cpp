class Solution {
public:
    vector<vector<int>> dp;

    bool helper(string &s , string &p, int i, int j){
        // base case
        if(i == s.length() && j == p.length()) return true;

        if(j == p.length()) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(i == s.length()){
            for (int k = j; k < p.length(); k++){
                if(p[k] != '*') return dp[i][j] = false;
            }
            return dp[i][j] = true;
        }

        if((s[i] == p[j]) || (p[j] == '?')){
            return dp[i][j] = helper(s, p , i+1, j+1);
        }

        if(p[j] == '*'){
            return dp[i][j] =
                helper(s,p,i,j+1) ||   // empty
                helper(s,p,i+1,j);     // consume
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        dp.assign(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(s,p,0,0);
    }
};