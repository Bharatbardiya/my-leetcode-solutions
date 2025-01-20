class Solution {
public:
    bool parseBoolExpr(string exp) {
        
        stack<char>st;
        set<char>ops = {'&', '|', '!'};

        int i = 0, n = exp.size();
        while(i<n){
            if(exp[i]==')'){
                vector<char>temp;
                while(ops.find(st.top())==ops.end()){
                    temp.push_back(st.top()); st.pop();
                }
                auto op = st.top(); st.pop();
                if(op=='&'){
                    char ch = 't';
                    for(auto c : temp){
                        if(c=='f'){ ch = 'f'; break;}
                    }
                    st.push(ch);
                }
                else if(op=='|'){
                    char ch = 'f';
                    for(auto c : temp){
                        if(c=='t'){ ch='t'; break;}
                    }
                    st.push(ch);
                }
                else {
                    char c = temp[0];
                    c = (c=='f')?'t':'f';
                    st.push(c);
                }
            }
            else if(ops.count(exp[i])>0){
                st.push(exp[i]);
            }
            else if(exp[i]=='(' or exp[i]==','){}
            else st.push(exp[i]);

            i++;
        }

        return st.top()=='t'? true : false;
    }
};