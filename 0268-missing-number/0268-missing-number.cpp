class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int Xor = 0, n = nums.size();
        for(int i = 0; i<=n; i++){
            Xor = (Xor^i);
            if(i!=n) Xor = (Xor^nums[i]);
        }
        return Xor;
    }
};