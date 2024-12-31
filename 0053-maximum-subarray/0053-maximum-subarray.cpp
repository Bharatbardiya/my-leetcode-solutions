class Solution {
public:
    int divideAndConquer(vector<int>&nums, int l, int r){
        cout<<l<<","<<r<<"),";
        if(l>r) return -1000000;
        else if(l==r) return nums[l];

        int mid = (l+r)/2;
        int left = divideAndConquer(nums, l, mid-1);
        int right = divideAndConquer(nums, mid+1, r);
        
        int ans = nums[mid];
        int leftMaxi = 0, rightMaxi = 0, i = mid-1, curr = 0;
        while(i>=l){
            curr+=nums[i]; i--;
            leftMaxi = max(curr, leftMaxi);
        }
        i = mid+1, curr = 0;
        while(i<=r){
            curr+=nums[i]; i++;
            rightMaxi = max(curr, rightMaxi);
        }
        return max(ans+leftMaxi+rightMaxi, max(left, right));
    }
    int maxSubArray(vector<int>& nums) {
        
        return divideAndConquer(nums, 0, nums.size()-1);
    }
};