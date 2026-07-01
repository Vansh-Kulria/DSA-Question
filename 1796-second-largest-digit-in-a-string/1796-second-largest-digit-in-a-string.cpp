class Solution {
public:
    int secondHighest(string s) {
        vector<int> nums;

        for(char ch : s){
            if(isdigit(ch)){
                int ger = ch - '0';

                if(find(nums.begin(), nums.end(), ger) == nums.end()){
                    nums.push_back(ger);
                }
            }
        }

        int largest = INT_MIN;
        int second = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > largest){
                second = largest;
                largest = nums[i];
            }
            else if(nums[i] > second && nums[i] != largest){
                second = nums[i];
            }
        }

        if(second == INT_MIN)
            return -1;

        return second;
    }
};