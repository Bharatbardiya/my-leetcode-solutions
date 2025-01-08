class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
	    string ans = "";
        unordered_map<string,string>mp;

        for(auto pr : knowledge){
                mp[pr[0]] = pr[1];
        }
        bool isKey = false;
        string key = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='('){
                isKey = true;
                continue;
            }
            else if(s[i]==')'){
                isKey = false;
                // cout<<key<<"|"<<mp[key]<<endl;
                if(mp.find(key)!=mp.end()) ans+=mp[key];
                else ans.push_back('?');
                key="";
                continue;
            }
            if(!isKey){
                ans.push_back(s[i]);
            } else{
                key.push_back(s[i]);
            }
        }
        return ans;
    }
};