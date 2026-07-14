class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int prefix = 0; 
        int count = 0;
        for(auto x : nums){
            prefix+=x;

            if(mp.count(prefix - k)){
                count += mp[prefix - k];
            }
                 mp[prefix]++;
        }

        return count;
    }
};