class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int>mp;
        for(auto x : nums){
            mp[x]++;
        }
        bool f = true;

        while(mp.size()>0){
            int j = 0;
            int prev = -1;
            for(auto it = mp.begin(); it!=mp.end() and j<k; it++){
                it->second--;
                if(prev!=-1 and prev+1!=it->first) return false;
                prev = it->first;
                if(it->second==0) mp.erase(it);
                j++;
            }
            if(j<k) return false;

            // for(auto pr : mp){
            //     cout<<pr.first<<","<<pr.second<<"),";
            // }
            // cout<<endl;
        }
        return true;
    }
};