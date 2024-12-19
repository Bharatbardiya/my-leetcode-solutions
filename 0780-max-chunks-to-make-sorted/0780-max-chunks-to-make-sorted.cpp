class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int sum = 0;
        int real_sum = 0, ans = 0;
        for(int i = 0; i<arr.size(); i++){
            sum+=arr[i];
            real_sum+=i;
            if(sum==real_sum) ans++;
        }
        return ans;
    }
};