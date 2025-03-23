class Solution {
public:
    int findSmaller(vector<pair<int,int>>&arr, int x){
        int i = 0, j = arr.size()-1;
        int ind = -1;
        while(i<=j){
            int mid = (i+j)/2;
            if(arr[mid].first>x) i = mid+1;
            else{
                j = mid-1;
                ind = arr[mid].second;
            }
        }
        return ind;
    }

    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>>arr;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int reqInd = findSmaller(arr, nums[i]);
            if(reqInd!=-1) ans = max(ans, i-reqInd);
            if(arr.size()==0 or arr.back().first>nums[i])
                arr.push_back({nums[i],i});
            
        }
        return ans;
    }
};