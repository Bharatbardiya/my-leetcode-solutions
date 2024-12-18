class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        stack<int>st;
        int ans = 0, n = target.size();

        for(int i = 0; i<n; i++){
            if(st.size()>0 and st.top()>target[i]){
                int maxi = st.top();
                while(st.size()>0 and st.top()>target[i]){
                    st.pop();
                }
                ans+=(maxi-target[i]);
            }
            st.push(target[i]);
        }
        return ans+st.top();
    }
};