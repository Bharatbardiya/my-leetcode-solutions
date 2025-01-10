class Solution {
public:
    string decodeString(string s) {
        
        stack<pair<int,string>>st;
        string num = "";

        for(int i = 0; i<s.length(); i++){
            string Temp = "";
            Temp.push_back(s[i]);
            if(s[i]>='a' and s[i]<='z'){
                st.push({0, Temp});
            }
            else if(s[i]>='0' and s[i]<='9'){
                num.push_back(s[i]);
            }
            else if(s[i]=='['){
                int temp = stoi(num);
                num = "";
                st.push({temp, Temp});
            }
            else{
                string curr = "";
                while(st.size()>0 and st.top().second!="["){
                    curr+=(st.top().second);
                    st.pop();
                }
                int feq = st.top().first;
                st.pop();
                // reverse(curr.begin(), curr.end());
                // cout<<feq<<","<<i<<","<<curr<<"),";
                string Curr = "";
                for(int j = 0; j<feq; j++) Curr+=curr;
                st.push({0,Curr});
            }
        }
        //curr = ccaccacca
        // accaccacc
        // {3,[}
        string ans = "";
        while(st.size()>0){
            ans+=st.top().second;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        // 3,[, a, 2, [, b,c, ], ]
        // 3, [ cbcba, ]
        // cbcbacbcba
        // abcbcabcbc
    }
};