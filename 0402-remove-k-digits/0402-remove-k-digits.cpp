class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string ans = "";
        for(int i = 0; i<num.size(); i++){
            // if(st.size()==0) st.push(num[i]);
            while(st.size()>0 and st.top()>num[i] and k>0){
                st.pop(); k--;
            }
            st.push(num[i]);
        }
        while(st.size()>0){
            char c = st.top();
            st.pop();
            if(k>0) k--;
            else ans.push_back(c);
        }
        while(ans.size()>1 and ans.back()=='0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans.size()==0?"0":ans;
    }
};