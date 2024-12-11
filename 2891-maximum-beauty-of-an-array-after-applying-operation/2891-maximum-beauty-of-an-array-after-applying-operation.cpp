class Solution {
public:
    int elementsInRange(vector<int>&nums, int l, int r){
    auto it_left = lower_bound(nums.begin(), nums.end(), l);
    int ind_left = it_left-nums.begin();
   
    auto it_right = upper_bound(nums.begin(), nums.end(), r);
    it_right--;
    int ind_right = it_right-nums.begin();
    
    return ind_right-ind_left+1;
}

int maximumBeauty(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int r = nums.back(), l = nums[0];
    int i = l, ans = 0;
    while(i<=r){
        int t1 = elementsInRange(nums, i-k, i+k);
        // if(i<n-1){
        // int mid1 = (val1+nums[i+1])/2;
        // int mid2 = mid1+1;
        // if(mid1!=nums[i]) t1 = max(t1, elementsInRange(nums, mid1-k, mid1+k));
        // if(mid2!=nums[i+1]) t1 = max(t1, elementsInRange(nums, mid2-k, mid2+k));
        // }
        i++;
        ans = max(ans, t1);
    }
      return ans;        
 }

};