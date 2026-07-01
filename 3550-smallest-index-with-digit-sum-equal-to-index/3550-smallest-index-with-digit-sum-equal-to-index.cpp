class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int countsum = 0;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            while(num){
            int lastdigit = num%10;
            countsum += lastdigit;
            num /= 10;
            }
            if(countsum == i){
                return i;
            }
            countsum = 0;
        }
        return -1;
    }
};