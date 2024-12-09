class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        set<int>st;
        int n = nums.size();
        for(int i = 0; i<n-1; i++){
            if(nums[i]%2==nums[i+1]%2){
                st.insert(i+1);
            }
        }
        // for(auto x : st) cout<<x<<",";
        // cout<<endl;
        vector<bool>ans;
        for(auto q : queries){
            int l = q[0], r = q[1];
            auto it = st.upper_bound(l);
            if(it!=st.end() and *it<=r){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};