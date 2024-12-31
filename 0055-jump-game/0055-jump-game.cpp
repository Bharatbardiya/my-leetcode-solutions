class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int>q;
        for(int i = 0; i<n-1; i++){
            if(nums[i]==0){
                if(q.size()==0 or q.top()<=i) return false;
            }
            else q.push(i+nums[i]);
        }
        return true;
    }
};