class Solution {
public:
    bool isValid(string s) {
        set<char>st = {')', '}', ']'};
        map<char,char>mp;
        mp['}'] = '{'; mp[')'] = '('; mp[']'] = '[';

        stack<char>my_stack;
        for(auto c : s){
            if(st.count(c)){
                if(my_stack.size()==0 or my_stack.top()!=mp[c]) return false;
                else my_stack.pop();
            }
            else{
                my_stack.push(c);
            }
        }
        return my_stack.empty();
    }
};