class Solution {
public:
    bool isPalindrome(string &s){
        int i = 0, j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    void explore(string &s, int i, string&curr, vector<string>&my_parti, vector<vector<string>>&ans){
        if(i>=s.length()){
            if(isPalindrome(curr)){
                my_parti.push_back(curr);
                ans.push_back(my_parti);
                my_parti.pop_back();
            }
            return;
        }

        curr.push_back(s[i]);
        explore(s, i+1, curr, my_parti, ans);
        curr.pop_back();
        
        if(curr.size()>0 and isPalindrome(curr)){
            string temp = curr;
            my_parti.push_back(curr);
            curr = ""; curr.push_back(s[i]);
            explore(s, i+1, curr, my_parti, ans);
            my_parti.pop_back();
            curr = temp;
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>my_parti;
        string curr = "";
        explore(s,0, curr, my_parti, ans);
        return ans;
    }
};