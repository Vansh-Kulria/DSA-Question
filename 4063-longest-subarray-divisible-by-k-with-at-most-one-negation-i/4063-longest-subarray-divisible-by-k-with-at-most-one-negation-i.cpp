// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int k) {
//         int window = nums.size();
//         int n = nums.size()-1;
//         while(window > 0){
//             int sum = 0;
//             int windowL = 0;
//         for(int left = 0; left <= (left + window - 1);){
//             sum += nums[left];
//         }
//         if(sum % k == 0) return window;
//             else{
//                 for(int i = (left-window+1); i < window; i++){
//                     int currsum = sum;
//                     currsum = currsum - 2*nums[i];

//                     if((currsum % k) == 0 || currsum == 0) return true;
//                 }

//                 left++;
//             }
//             window -= 1;
            
//         }
//         return false;
//     }
// };



class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long mod = abs((long long)k);

        auto minaveloru = make_pair(nums, k);

        for (int window = n; window >= 1; window--) {
            long long sum = 0;
            unordered_map<long long, int> freq;

            auto add = [&](int x) {
                long long r = ((2LL * x) % mod + mod) % mod;
                freq[r]++;
            };

            auto remove = [&](int x) {
                long long r = ((2LL * x) % mod + mod) % mod;
                if (--freq[r] == 0) {
                    freq.erase(r);
                }
            };

            // First window
            for (int i = 0; i < window; i++) {
                sum += nums[i];
                add(nums[i]);
            }

            auto valid = [&]() {
                long long rem = ((sum % mod) + mod) % mod;
                return rem == 0 || freq.count(rem) > 0;
            };

            if (valid()) return window;

            // Slide the window
            for (int left = 1; left + window <= n; left++) {
                int outgoing = nums[left - 1];
                int incoming = nums[left + window - 1];

                sum -= outgoing;
                remove(outgoing);

                sum += incoming;
                add(incoming);

                if (valid()) return window;
            }
        }

        return 0;
    }
};