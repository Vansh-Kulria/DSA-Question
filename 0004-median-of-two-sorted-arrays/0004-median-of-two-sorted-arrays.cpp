class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // brute force method
        float median;
        int m = nums1.size();
        int n = nums2.size();
        vector<int> merged = nums1;
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        sort(merged.begin(), merged.end());
        int total = m + n;
        if (total & 1) {
            median = merged[total >> 1];
        } else {
            median = (merged[total >> 1] + merged[(total >> 1) - 1]) / 2.0;
        }
        return median;
    }
};