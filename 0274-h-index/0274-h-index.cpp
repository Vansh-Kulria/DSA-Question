class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int h = n; h >= 0; h--) {
            int cnt = 0;

            for (int x : citations) {
                if (x >= h)
                    cnt++;
            }

            if (cnt >= h) {
                return h;
            }
        }
        return 0;
    }
};