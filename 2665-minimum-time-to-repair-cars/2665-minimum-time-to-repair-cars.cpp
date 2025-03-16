class Solution {
public:
    bool possible(vector<int>&ranks, long long cars, long long mid){
        for(auto rank : ranks){
            cars -= (long long)sqrt(mid/rank);
        }
        return cars<=0;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1e17;
        long long ans = right;
        while(left<=right){
            long long mid = (left+right)/2;
            if(possible(ranks, cars, mid)){
                ans = mid; right = mid-1;
            }
            else left = mid+1;
        }
        return ans;
    }
};