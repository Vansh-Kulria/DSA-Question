class Solution {
public:
    bool canDistributeHelper(vector<int>& counts, vector<int>& quantity, int ithCustomer) {
        // base case: all customers have been satisfied
        if (ithCustomer == quantity.size()) {
            return true;
        }
        // 1 case solve
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] >= quantity[ithCustomer]) {
                counts[i] -= quantity[ithCustomer];
                if (canDistributeHelper(counts, quantity, ithCustomer + 1)) {
                    return true;
                }
                counts[i] += quantity[ithCustomer]; // backtrack
            }
        }
        return false; // no valid distribution found for this customer

    }

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        vector<int> counts;
        for (auto& p : freq) {
            counts.push_back(p.second);
        }
        sort(quantity.rbegin(), quantity.rend()); // sort quantity in descending order for optimization
        return canDistributeHelper(counts, quantity, 0);
    }
};