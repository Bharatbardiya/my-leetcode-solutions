class Solution {
public:
    long long findScore(vector<int>& nums) {
        set<pair<int,int>>st;
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i<n; i++){
            st.insert({nums[i], i});
        }

        vector<bool>vis(n,false);
        while(st.size()>0){
            auto it = st.begin();
            int ind = it->second, val = it->first;
            st.erase(it);
            ans+=val;
            vis[ind] = false;

            if(ind>0 and vis[ind-1]==false){
                int valLeft = nums[ind-1];
                st.erase({valLeft, ind-1});
                vis[ind-1] = false;
            }
            if(ind<n-1 and vis[ind+1]==false){
                int valRight = nums[ind+1];
                st.erase({valRight, ind+1});
                vis[ind+1] = false;
            }
        }
        return ans;
    }
};