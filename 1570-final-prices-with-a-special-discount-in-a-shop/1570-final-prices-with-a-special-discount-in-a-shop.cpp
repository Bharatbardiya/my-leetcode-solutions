class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // 8,4,6,2,3 | {} [3]
        // [2,3] | {2}
        // [4,2,3] | {6,2}
        //  [2,4,2,3]  | {4,2}
        // [4,2,4,2,3] | {8,4,2}

        int n = prices.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i = n-1; i>=0; i--){
            while(st.size()>0 and st.top()>prices[i]){
                st.pop();
            }
            if(st.size()>0){
                ans[i] = prices[i]-st.top();
            }
            else ans[i] = prices[i];
            st.push(prices[i]);
        }
        return ans;
    }
};