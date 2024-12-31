class Solution {
public:
    int fun(vector<int>&nums, int i, vector<int>&curr){
        if(curr.size()==4){
            return (curr[0]*curr[2]==curr[1]*curr[3]);
        }

        if(i>=nums.size()){
            return 0;
        }

        int val1 = fun(nums, i+1, curr);
        curr.push_back(nums[i]);
        int val2 = fun(nums, i+2, curr);
        curr.pop_back();
        return val1+val2;
    }
    int gcd(int x, int y){
        if(y>x) return gcd(y,x);
        if(y==0) return x;
        return gcd(y, x%y);
    }

    long long numberOfSubsequences(vector<int>& nums) {
        // vector<int>curr;
        //int ans = fun(nums, 0, curr);
        // return ans;
        // 3,4,3,4
        // 
        // 1/2
        // 3,3,4,4
        // nums[p] * nums[r] == nums[q] * nums[s]
        // (nums[p]/nums[q]) == (nums[s]/nums[r])
        // nums[s] = (nums[r]*nums[p])/nums[q];
        int n = nums.size();
        
        map<pair<int,int>,int>mp;
        long long ans = 0;
        for(int j = n-5; j>=2; j--){
            int r = nums[j+2];
            for(int s = j+4; s<n; s++){
                int x = nums[s], y = r;
                int Gcd = gcd(x,y);
                x = x/Gcd; y = y/Gcd;
                mp[{x,y}]++;
            }
            for(int p = 0; p<j-1; p++){
                int x = nums[p], y = nums[j];
                int Gcd = gcd(x,y);
                x = x/Gcd; y = y/Gcd;
                ans += mp[{x,y}];
            }
        }
        return ans;
    }
};