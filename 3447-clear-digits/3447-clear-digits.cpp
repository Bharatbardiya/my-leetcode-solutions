class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto c : s){
            if(isdigit(c)){
                if(st.size()==0 or isdigit(st.top())) st.push(c);
                else st.pop();
            }
            else st.push(c);
        }
        string ans = "";
        while(st.size()>0){
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};