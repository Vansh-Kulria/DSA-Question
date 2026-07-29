class Solution {
public:
    bool isPalindrome(string s) {

        string res;

        for(char ch : s){

            if(ch >= 'A' && ch <= 'Z')
                res.push_back(ch + ('a' - 'A'));

            else if(ch >= 'a' && ch <= 'z')
                res.push_back(ch);

            else if(ch >= '0' && ch <= '9')
                res.push_back(ch);
        }

        int i = 0;
        int j = res.size() - 1;

        while(i < j){

            if(res[i] != res[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};