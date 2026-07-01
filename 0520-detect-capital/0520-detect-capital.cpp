class Solution {
public:
    bool detectCapitalUse(string word) {

        int firstLower = -1;
        int lastUpper = -1;
        int upperCount = 0;

        for(int i = 0; i < word.size(); i++) {

            char ch = word[i];

            // uppercase
            if(ch >= 'A' && ch <= 'Z') {

                upperCount++;
                lastUpper = i;
            }

            // lowercase
            else {

                if(firstLower == -1) {
                    firstLower = i;
                }
            }
        }

        // all uppercase
        if(upperCount == word.size())
            return true;

        // all lowercase
        if(upperCount == 0)
            return true;

        // only first letter uppercase
        if(upperCount == 1 && lastUpper == 0)
            return true;

        return false;
    }
};