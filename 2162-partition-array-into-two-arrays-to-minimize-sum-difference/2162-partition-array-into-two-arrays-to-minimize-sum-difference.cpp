class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size();
        // if(N==2) return abs(nums[0]-nums[1]);
        int n = N/2;
        int sum = 0;
        for(auto x : nums) sum+=x;
        vector<vector<int>>left(n+1), right(n+1);
        left[0].push_back(0);
        right[0].push_back(0);
        for(int mask = 0; mask<(1<<n); mask++){
            int size = 0;
            int l = 0, r = 0;
            for(int i = 0; i<n; i++){
                if(mask&(1<<i)){
                    size++;
                    l+=nums[i];
                    r+=nums[n+i];
                }
            }
            left[size].push_back(l);
            right[size].push_back(r);

        }
        int ans = INT_MAX;
        for(int i = 0; i<=n; i++){
            sort(right[i].begin(), right[i].end());
        }
        int Answer = INT_MAX;
        for(int i = 0; i<n; i++){
            for(auto x : left[i]){
                int target = sum/2-x;
                auto it = lower_bound(right[n-i].begin(), right[n-i].end(), target);
                if(it!=right[n-i].end()){
                    int t1 = *it;
                    int temp = x+t1;
                    Answer = min(Answer, abs(sum-2*temp));
                }
                if(it!=right[n-i].begin()){
                    it--;
                    // cout<<*it<<","<<x<<endl;
                    int temp = *it+x;
                    Answer = min(Answer, abs(sum-2*temp));
                }
            }
        }
        return Answer;
    }
};