class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string,string>>letter_logs, digit_logs;
        
        for(int i = 0; i<logs.size(); i++){
            string id = "", content = "";
            bool first_space = false;
            for(int j = 0; j<logs[i].size(); j++){
                if(!first_space and logs[i][j]==' '){
                    first_space=true; continue;
                }
                if(!first_space) id.push_back(logs[i][j]);
                else content.push_back(logs[i][j]);
            }
            if(content[0]>='0' and content[0]<='9'){
                digit_logs.push_back({content, id});
            }
            else letter_logs.push_back({content, id});
        }
        sort(letter_logs.begin(), letter_logs.end());

        vector<string>ans;
        for(auto pr : letter_logs){
            ans.push_back(pr.second + " " + pr.first);
        }
        for(auto pr : digit_logs){
            ans.push_back(pr.second+ " " +pr.first);
        }
        return ans;
    }
};