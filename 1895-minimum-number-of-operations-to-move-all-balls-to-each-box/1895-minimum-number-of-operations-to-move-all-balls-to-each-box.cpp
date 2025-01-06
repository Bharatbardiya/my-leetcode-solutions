class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>pre(n,0);
        int ones = 0;
        for(int i = 0; i<n; i++){
            if(i>0) pre[i] = pre[i-1];
            pre[i]+=ones;
            if(boxes[i]=='1') ones++;
        }
        int ones_right=0, post = 0;
        vector<int>ans(n);
        for(int i = n-1; i>=0; i--){
            int temp = post;
            temp+=ones_right;
            if(boxes[i]=='1') ones_right++;
            post = temp;
            ans[i] = pre[i]+post;
        }
        return ans;
    }
};