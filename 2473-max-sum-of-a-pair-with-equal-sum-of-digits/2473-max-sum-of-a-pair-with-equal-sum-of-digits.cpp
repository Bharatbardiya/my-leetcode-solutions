class Solution {
public:
    int digitSum(int x){
        int ans = 0;
        while(x>0){
            ans += (x%10);
            x = x/10;
        }
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, multiset<int> >mp;
        int Ans = -1;
        for(auto x : nums){
            int digit_sum = digitSum(x);
            mp[digit_sum].insert(x);
            if(mp[digit_sum].size()>2)
                mp[digit_sum].erase(mp[digit_sum].begin());
        }
        for(auto pr : mp){
            // cout<<pr.first<<","<<pr.second.size()<<"),";
            if(pr.second.size()==2){
                int temp = 0;
                for(auto t : pr.second) temp+=t;
                Ans = max(Ans, temp);
            }
        }
        return Ans;
    }
};