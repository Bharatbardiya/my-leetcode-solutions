class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string temp = "";
        for(auto c : s){
            if(c==' '){
                reverse(temp.begin(), temp.end());
                ans+=temp;
                if(temp.size()>0) ans.push_back(c);
                temp = "";
            }
            else{
                temp.push_back(c);
            }
        }
        reverse(temp.begin(), temp.end());
        ans+=temp;
        if(ans.back()==' ') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};