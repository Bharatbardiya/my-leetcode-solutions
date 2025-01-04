class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int v1 = (n*(n+1))/2;
        for(auto x : nums) v1-=x;
        return v1;
    }
};