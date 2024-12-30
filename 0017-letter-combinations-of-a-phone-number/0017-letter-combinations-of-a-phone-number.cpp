class Solution {
public:
    void fillmap(map<int,vector<char>>&mp){
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};
    }

    void explore(string &s, int i, string &curr, vector<string>&ans, map<int,vector<char>>&mp){
        if(i==s.length()){
            ans.push_back(curr); return;
        }
        int x = s[i]-'0';
        for(auto c : mp[x]){
            curr.push_back(c);
            explore(s, i+1, curr, ans, mp);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        map<int,vector<char>>mp;
        fillmap(mp);

        vector<string>ans;
        string curr;

        explore(digits, 0, curr, ans, mp);
        return ans;
    }
};