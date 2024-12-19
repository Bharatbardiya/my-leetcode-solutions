class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0, ans = 0;
        for(int i = 0; i<arr.size(); i++){
            sum+=arr[i];
            sum-=i;
            if(!sum) ans++;
        }
        return ans;
    }
};