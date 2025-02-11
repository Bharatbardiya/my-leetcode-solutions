class Solution {
public:
    void removeIfAny(stack<char>&st, string &part){
        int n = part.size();
        if(n>st.size()) return;
        stack<char>temp;

        while(n>0){
            if(st.top()==part[n-1]){
                temp.push(st.top()); st.pop(); n--;
            } else break;
        }
        if(n>0){
            while(temp.size()>0){
                st.push(temp.top()); temp.pop();
            }
        }
    }

    string removeOccurrences(string s, string part) {
        stack<char>st;

        for(auto c : s){
            st.push(c);
            removeIfAny(st, part);
        }
        string curr = "";
        while(st.size()>0){
            curr.push_back(st.top()); st.pop();
        }
        reverse(curr.begin(), curr.end());
        return curr;
    }
};