class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        if(source.size() < 2) return false;

        long long int sum = 0;
        for(int i = 0; i < source.size(); i++){
            sum = sum + source[i] - target[i];
        }
        if(sum == 0) return true;
            return false;
    }
};