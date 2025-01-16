class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1%2!=0){
            for(auto x : nums2) ans = (ans^x);
        }
        if(n2%2!=0){
            for(auto x : nums1) ans = (ans^x);
        }
        return ans;
    }
};