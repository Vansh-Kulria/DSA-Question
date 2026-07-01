class Solution {
public:
    int numberOfSpecialChars(string word) {
        // bruteforce
        vector<int>lastlower(26, -1);
        vector<int>firstupper(26,-1);

        for(int i = 0 ; i < word.size(); i++){
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z'){
                int idx = ch - 'a';
                lastlower[idx] = i;
            }
            else{
                int idx = ch-'A';
                if(firstupper[idx] == -1){
                    firstupper[idx] = i;
                }
            }
        }
         int count = 0;

        // check all 26 letters
        for(int i = 0; i < 26; i++) {

            if(lastlower[i] != -1 &&
               firstupper[i] != -1 &&
               lastlower[i] < firstupper[i]) {

                count++;
            }
        }

        return count;
    }
};