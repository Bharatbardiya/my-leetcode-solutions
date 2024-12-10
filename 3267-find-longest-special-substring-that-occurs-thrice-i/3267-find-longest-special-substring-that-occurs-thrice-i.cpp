class Solution {
public:
     int maximumLength(string s) {
        	int n = s.length();
       	map<string,int>mp;
	for(int i = 0; i<n; i++){
		string curr = "";
		for(int j = i; j<n; j++){
			if(curr.length()==0 or curr.back()==s[j]){
                curr.push_back(s[j]);
                mp[curr]++;
            }
			else break;
		}
}
int ans  = -1;
for(auto pr : mp){
	string key = pr.first;
	int val = pr.second;
    cout<<key<<","<<val<<"),";
	if(val>=3){
		ans = max(ans,(int)key.length());
    }
}
return ans;
    }

};