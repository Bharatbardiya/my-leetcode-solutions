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
    int right_ptr = 0, left_ptr = 0, ans=0;
    while(right_ptr<n){
        if(nums[right_ptr] - nums[left_ptr]<=2*k){
            ans = max(ans, right_ptr-left_ptr+1);
            right_ptr++;
        }
        else{
            left_ptr++;
        }
    } 
    ans = max(ans, n-left_ptr);
    return ans;        
 }


};