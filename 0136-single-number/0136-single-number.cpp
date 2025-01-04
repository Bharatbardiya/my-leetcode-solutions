class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto y : nums){
            x = (x^y);
        }
        return x;
    }
};