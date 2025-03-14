class Solution {
public:
    bool possible(vector<int>&candies, int mid, long long k){
        if(mid==0) return true;
        for(auto x : candies){
            k -= (x/mid);
        }
        return k<=0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int high = 1e7, low = 0;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(candies, mid, k)){
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return ans;
    }
};