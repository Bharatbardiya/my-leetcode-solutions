class Solution {
public:
    string formStr(vector<string>&words, int start, int end, int Extraspace){
        cout<<start<<","<<end<<","<<Extraspace<<endl;
        string ans = "";
        if(start==end){
            string temp(Extraspace, ' ');
            ans+=words[start];
            ans+=temp;
            return ans;
        }
        int spaces = end-start;
        int div = Extraspace/spaces, rem = Extraspace%spaces;
        for(int i = start; i<=end; i++){
            ans+=(words[i]);
            if(i!=end){
                int len = div+1;
                if(rem>0){
                    rem--; len++;
                }
                string temp = "";
                for(int k = 0; k<len; k++) temp.push_back(' ');
                ans+=temp;
            }
        }
        return ans;
    }

    void createStr(vector<string>&words, int start, int remWidth, int i, int maxWidth, vector<string>&ans){
        if(i==words.size()){
            if(remWidth==maxWidth) return;
            string temp = "";
            for(int j = start; j<i; j++){
                temp = temp+words[j];
                if(j!=i-1) temp.push_back(' ');
            }
            int len = maxWidth-temp.size();
            for(int j = 0; j<len; j++) temp.push_back(' ');
            ans.push_back(temp); return;
        }
        if(words[i].size() < remWidth){
            remWidth -= words[i].size();
            remWidth--;
            createStr(words, start, remWidth, i+1, maxWidth, ans);
            return;
        }
        else if(words[i].size()==remWidth){
            string curr = formStr(words, start, i, 0);
            ans.push_back(curr);
            createStr(words, i+1, maxWidth, i+1, maxWidth, ans);
            return;
        }
        string curr = formStr(words, start, i-1, remWidth+1);
        ans.push_back(curr);
        createStr(words, i, maxWidth, i, maxWidth, ans);
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        createStr(words,0, maxWidth, 0, maxWidth, ans);
        return ans;
    }
};