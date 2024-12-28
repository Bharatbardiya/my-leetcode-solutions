class Solution {
public:
    void fun(vector<string>&ans, string &curr, int x, int y){
        if(x==0 and y==0){
            ans.push_back(curr);
            return;
        }
        if(x==0){
            curr.push_back(')');
            fun(ans, curr, x, y-1);
            curr.pop_back();
            return;
        }
        
        curr.push_back('(');
        fun(ans, curr, x-1, y);
        curr.pop_back();

        if(x<y){
            curr.push_back(')');
            fun(ans, curr, x, y-1);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string>ans;
        fun(ans, curr, n, n);
        return ans;
    }
};