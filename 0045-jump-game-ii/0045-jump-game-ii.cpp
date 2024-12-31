class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        queue<int>q;
        vector<int>vis(n, false);
        int ans = 0;

        q.push(0); vis[0] = false;

        while(q.size()>0){
            int x = q.size();
            for(int i = 0; i<x; i++){
                int t = q.front(); q.pop();
                if(t==n-1) return ans;
                for(int j = t+1; j<=min(t+nums[t], n-1); j++){
                    if(vis[j]==false){
                        vis[j] = true; q.push(j);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};