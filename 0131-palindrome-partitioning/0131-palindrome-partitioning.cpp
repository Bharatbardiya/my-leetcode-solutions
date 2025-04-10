class Solution {
public:
    bool isPal(string &s){
        if(s.length()==0) return false;
        int i = 0, j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    void fun(string &s, vector<vector<string>>&ans, vector<string>&curr, string &t, int i){
        if(i==s.length()){
            if(isPal(t)){
                curr.push_back(t);
                ans.push_back(curr);
                curr.pop_back();
            }
            return;
        }

        if(isPal(t)){
            curr.push_back(t);
            string tt = "";
            fun(s, ans, curr, tt, i);
            curr.pop_back();

            t.push_back(s[i]);
            fun(s, ans, curr, t, i+1);
            t.pop_back();
        }
        else{
            t.push_back(s[i]);
            fun(s, ans, curr, t, i+1);
            t.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        string t = "";

        fun(s, ans, curr, t, 0);
        return ans;
    }
};