class Solution {
public:
    class OrOperations{
        vector<int>feq;
        public:
        OrOperations(){
            feq.resize(32,0);
        }
        void addOr(int x){
            for(int i = 0; i<32; i++){
                if(((x>>i)&1)==1) feq[i]++;
            }
        }
        void removeOr(int x){
            for(int i = 0; i<32; i++){
                if(((x>>i)&1)==1) feq[i]--;
            }
        }
        int value(){
            int ans = 0;
            for(int i = 0; i<32; i++){
                if(feq[i]>0) ans = (ans|(1<<i));
            }
            return ans;
        }
    };
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int i = 0, j = 0, ans = INT_MAX;
        OrOperations *obj = new OrOperations();
        while(j<nums.size()){
            obj->addOr(nums[j]);
            while(i<=j and obj->value()>=k){
                ans = min(ans,(j-i+1));
                obj->removeOr(nums[i]); i++;
            }
            j++;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};