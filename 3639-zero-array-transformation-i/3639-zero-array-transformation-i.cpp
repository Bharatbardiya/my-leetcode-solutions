class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int>mark(n+1);
        int prefixSum = 0;
        for(auto q : queries){
            mark[q[0]]++;
            mark[q[1]+1]--;
        }
        
        for(int i = 0; i<n; i++){
            prefixSum+=mark[i];
            if(nums[i]-prefixSum>0) return false;
        }
        return true;
    }
};